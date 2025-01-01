#include "ui/button.hpp"
#include "log.hpp"
#include <SDL_image.h>
#include <SDL_render.h>

namespace tysm {
Button::Button(ButtonInfo info)
    : TyObject(info.renderer, info.name, info.pos, info.sizeScaler)
    , text(info.text)
    , imgPath(info.imgPath)
    , bgColor(info.bgColor)
    , borderColor(info.borderColor)
    , font(info.font)
{
    initImgTexture();
    initTextTexture();
}

void Button::initTextTexture()
{
    if (font == nullptr || text == nullptr)
        return;
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text, fontColor);
    if (!surface) {
        TY_CORE_ERROR("Create text surface failed", SDL_GetError());
        text = nullptr;
        return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
        TY_CORE_ERROR("Create text texture failed", TTF_GetError());
    SDL_FreeSurface(surface);
    text = nullptr;
}

void Button::initImgTexture()
{
    if (imgPath == nullptr)
        return;
    bgTexture = IMG_LoadTexture(renderer, imgPath);
    if (!texture)
        TY_CORE_ERROR(IMG_GetError());
    imgPath = nullptr;
}

void Button::bindOnClick(std::function<void()> func)
{
    onClickFunc = func;
}

void Button::bindOnFloat(std::function<void()> func)
{
    onFloatFunc = func;
}

void Button::update(SDL_Event &e, CanvasData &canvasData)
{
    if (text != nullptr)
        initTextTexture();
    if (imgPath != nullptr)
        initImgTexture();
    if (isClick(e, canvasData) && onClickFunc != nullptr)
        onClickFunc();
}

void Button::render(CanvasData &canvasData)
{
    // update rect
    x = static_cast<int>(canvasData.w * pos.xScaler + canvasData.xOffset);
    y = static_cast<int>(canvasData.h * pos.yScaler + canvasData.yOffset);
    w = static_cast<int>(canvasData.w * sizeScaler.wScaler);
    h = static_cast<int>(canvasData.h * sizeScaler.hScaler);
    if (!dstRect)
        delete dstRect;
    dstRect = new SDL_Rect{x, y, w, h};

    //draw bg color
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b,
                           bgColor.a);
    SDL_RenderFillRect(renderer, dstRect);
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g,
                           borderColor.b, borderColor.a);
    SDL_RenderDrawRect(renderer, dstRect);
}

bool Button::isFloat(SDL_Event &e, CanvasData &canvasData) {}

bool Button::isClick(SDL_Event &e, CanvasData &canvasData)
{
    return 1;
}
} // namespace tysm
