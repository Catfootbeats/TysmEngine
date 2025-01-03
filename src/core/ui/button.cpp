#include "ui/button.hpp"
#include "log.hpp"
#include "render/render_helper.cpp"
#include "utils/coordinate_convert.cpp"
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_surface.h>

namespace tysm {
Button::Button(ButtonInfo info)
    : TyObject(info.renderer, info.name, info.pos, info.size)
    , info_(info)
    , infoCopy(info)
{
    createImageTexture(info_);
    createTextTexture(info_);
}

Button::~Button()
{ // 析构函数调用先Button 后ty object
    delete textRect;
    SDL_DestroyTexture(bgTexture);
    SDL_DestroyTexture(textTexture);
}

void Button::draw(SDL_Texture *canvas)
{
    // 渲染顺序
    // 底色 -> 图片 -> 文字 -> 边框
    delete dstRect;
    dstRect = new SDL_Rect{pos.x, pos.y, size.w, size.h};
    // 底色
    SDL_SetRenderDrawColor(renderer, info_.bgColor.r, info_.bgColor.g,
                           info_.bgColor.b, info_.bgColor.a);
    SDL_RenderFillRect(renderer, dstRect);
    // 图片
    if (bgTexture != nullptr)
        SDL_RenderCopy(renderer, bgTexture, nullptr, dstRect);
    // 文字
    if (textTexture != nullptr && textRect != nullptr) {
        textRect->x = pos.x + (size.w - textRect->w) / 2;
        textRect->y = pos.y + (size.h - textRect->h) / 2;
        SDL_RenderCopy(renderer, textTexture, nullptr, textRect);
    }
    // 边框
    SDL_SetRenderDrawColor(renderer, info_.borderColor.r, info_.borderColor.g,
                           info_.borderColor.b, info_.borderColor.a);
    render::DrawRectWidth(renderer, dstRect, info_.borderWidth);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Button::createTextTexture(const ButtonInfo &info)
{
    //若不传入text或者fontPath则不创建text
    if (info.fontPath == nullptr || info.text == nullptr) {
        return;
    }
    font_ = TTF_OpenFont(info.fontPath, info.fontSize);
    SDL_Surface *surface =
        TTF_RenderUTF8_Blended(font_, info.text, info.fontColor);
    if (!surface) {
        TY_CORE_ERROR("Create text surface failed: {}", TTF_GetError());
        return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!textTexture)
        TY_CORE_ERROR("Create text texture failed: {}", SDL_GetError());
    delete textRect;
    textRect = new SDL_Rect;
    textRect->w = surface->w;
    textRect->h = surface->h;
    SDL_FreeSurface(surface);
    TTF_CloseFont(font_);
}

void Button::createImageTexture(const ButtonInfo &info)
{
    //同理 若没路径认为不设定图片
    if (info.imgPath == nullptr)
        return;
    bgTexture = IMG_LoadTexture(renderer, info.imgPath);
    if (!bgTexture)
        TY_CORE_ERROR("Create {} image texture failed: {}", name,
                      IMG_GetError());
}

void Button::bindOnClick(std::function<void()> func)
{
    onClickFunc = func;
}

void Button::bindOnFloat(std::function<void()> func)
{
    onFloatFunc = func;
}

void Button::update(SDL_Event &e, SDL_Rect &canvasRect, SDL_Window *&window)
{
    if (chechIsFloat(e, canvasRect, window) && onFloatFunc != nullptr)
        onFloatFunc();
    if (chechIsClick(e, canvasRect, window) && onClickFunc != nullptr)
        onClickFunc();
}

bool Button::chechIsFloat(SDL_Event &e,
                          SDL_Rect &canvasRect,
                          SDL_Window *&window)
{
    if (e.type == SDL_MOUSEMOTION && dstRect != nullptr) {
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_INPUT_FOCUS) {
            SDL_Rect actRect{pos.x, pos.y, size.w, size.h};
            toActualRect(actRect, canvasRect);
            if (e.motion.x > actRect.x && e.motion.y > actRect.y &&
                e.motion.x < (actRect.x + actRect.w) &&
                e.motion.y < (actRect.y + actRect.h)) {
                isOnFloat = true;
                return true;
            }
        }
    }
    if (isOnFloat) {
        //TODO: 结束on float恢复ui
    }
    isOnFloat = false;
    return false;
}

bool Button::chechIsClick(SDL_Event &e,
                          SDL_Rect &canvasRect,
                          SDL_Window *&window)
{
    //TODO:
    return true;
}
} // namespace tysm
