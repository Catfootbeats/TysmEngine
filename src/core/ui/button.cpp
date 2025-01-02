#include "ui/button.hpp"
#include "log.hpp"
#include <SDL_image.h>
#include <SDL_render.h>

namespace tysm {
Button::Button(ButtonInfo info)
    : TyObject(info.renderer, info.name, info.pos, info.size)
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

void Button::update(SDL_Event &e, SDL_Rect &canvasData)
{
    if (text != nullptr)
        initTextTexture();
    if (imgPath != nullptr)
        initImgTexture();
    if (isClick(e, canvasData) && onClickFunc != nullptr)
        onClickFunc();
}

bool Button::isFloat(SDL_Event &e, SDL_Rect &canvas) {
    //TODO:
    return 0;}

bool Button::isClick(SDL_Event &e, SDL_Rect &canvas)
{
    //TODO:
    return 1;
}
} // namespace tysm
