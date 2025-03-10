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
    , infoCopy_(info)
{
    createImageTexture(info_);
    createTextTexture(info_);
}

void Button::draw(SDL_Texture *canvas)
{
    // 渲染顺序
    // 底色 -> 图片 -> 文字 -> 边框
    dstRect = SDL_Rect{pos.x, pos.y, size.w, size.h};
    // 底色
    SDL_SetRenderDrawColor(renderer, info_.bgColor.r, info_.bgColor.g,
                           info_.bgColor.b, info_.bgColor.a);
    SDL_RenderFillRect(renderer, &dstRect);
    // 图片
    if (bgTexture != nullptr)
        SDL_RenderCopy(renderer, bgTexture.get(), nullptr, &dstRect);
    // 文字
    if (textTexture != nullptr && textRect.w != 0) {
        textRect.x = pos.x + (size.w - textRect.w) / 2;
        textRect.y = pos.y + (size.h - textRect.h) / 2;
        SDL_RenderCopy(renderer, textTexture.get(), nullptr, &textRect);
    }
    // 边框
    SDL_SetRenderDrawColor(renderer, info_.borderColor.r, info_.borderColor.g,
                           info_.borderColor.b, info_.borderColor.a);
    render::DrawRectWidth(renderer, &dstRect, info_.borderWidth);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Button::createTextTexture(const ButtonInfo &info)
{
    //若不传入text或者fontPath则不创建text
    if (info.fontPath == nullptr || info.text == nullptr) {
        return;
    }
    font_ = std::unique_ptr<TTF_Font, FontDeleter>(
        TTF_OpenFont(info.fontPath, info.fontSize));
    SDL_Surface *surface =
        TTF_RenderUTF8_Blended(font_.get(), info.text, info.fontColor);
    if (!surface) {
        TY_CORE_ERROR("Create text surface failed: {}", TTF_GetError());
        return;
    }
    textTexture = std::unique_ptr<SDL_Texture, TextureDeleter>(
        SDL_CreateTextureFromSurface(renderer, surface));
    if (!textTexture)
        TY_CORE_ERROR("Create text texture failed: {}", SDL_GetError());
    textRect.w = surface->w;
    textRect.h = surface->h;
    SDL_FreeSurface(surface);
    font_.reset();
}

void Button::createImageTexture(const ButtonInfo &info)
{
    //同理 若没路径认为不设定图片
    if (info.imgPath == nullptr)
        return;
    bgTexture = std::unique_ptr<SDL_Texture, TextureDeleter>(
        IMG_LoadTexture(renderer, info.imgPath));
    if (!bgTexture)
        TY_CORE_ERROR("Create {} image texture failed: {}", name,
                      IMG_GetError());
}

void Button::bindOnLeftClick(std::function<void()> func)
{
    onLeftClickFunc = func;
}

void Button::bindOnRightClick(std::function<void()> func)
{
    onRightClickFunc = func;
}

void Button::bindOnFloat(std::function<void()> func)
{
    onFloatFunc = func;
}

void Button::update(SDL_Event &e, SDL_Rect &canvasRect)
{
    checkIsFloat(e, canvasRect);
    checkIsClick(e);
}

// 负责了onFloat事件的判断和处理
void Button::checkIsFloat(const SDL_Event &e,
                          const SDL_Rect &canvasRect)
{
    if (dstRect.w > 0) {
        if (e.type == SDL_MOUSEMOTION) {
            SDL_Rect actRect{pos.x, pos.y, size.w, size.h};
            toActualRect(actRect, canvasRect);
            if (e.motion.x > actRect.x && e.motion.y > actRect.y &&
                e.motion.x < (actRect.x + actRect.w) &&
                e.motion.y < (actRect.y + actRect.h)) {
                if (!isOnFloat) {
                    // 只会运行一次
                    // 记录ui
                    infoCopy_ = info_;
                    isOnFloat = true;
                    if (onFloatFunc != nullptr)
                        onFloatFunc();
                }
                return;
            }
            if (isOnFloat) {
                // 结束on float恢复ui
                info_ = infoCopy_;
                createTextTexture(info_);
                createImageTexture(info_);
                isOnFloat = false;
            }
        }
    }
}
// 负责onClick事件的判断和处理
void Button::checkIsClick(const SDL_Event &e)const
{
    if (isOnFloat) {
        if (e.type == SDL_MOUSEBUTTONDOWN && dstRect.x > 0) {
            if (onLeftClickFunc != nullptr &&
                e.button.button == SDL_BUTTON_LEFT) {
                // 左键按下
                onLeftClickFunc();
            }
            if (onRightClickFunc != nullptr &&
                e.button.button == SDL_BUTTON_RIGHT) {
                // 左键按下
                onRightClickFunc();
            }
        }
    }
}

void Button::setText(const char *text)
{
    info_.text = text;
    createTextTexture(info_);
}
void Button::setFont(const char *fontPath)
{
    info_.fontPath = fontPath;
    createTextTexture(info_);
}
void Button::setFontSize(int fontSize)
{
    info_.fontSize = fontSize;
    createTextTexture(info_);
}
void Button::setImage(const char *path)
{
    info_.imgPath = path;
    createImageTexture(info_);
}
void Button::setBgColor(SDL_Color color)
{
    info_.bgColor = color;
}
void Button::setBorder(SDL_Color borderColor, int width)
{
    info_.borderColor = borderColor;
    info_.borderWidth = width;
}
} // namespace tysm
