#include "ui/text.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>

namespace tysm {
Text::Text(const TextInfo &info)
    : TyObject(info.renderer, info.name, info.pos, 1), info_(info)
{
    createTexture(info_);
}

void Text::setText(const char *text)
{
    info_.text = text;
    createTexture(info_);
}

void Text::setFont(const char *fontPath)
{
    info_.fontPath = fontPath;
    createTexture(info_);
}

void Text::setFontSize(const int fontSize)
{
    info_.fontSize = fontSize;
    createTexture(info_);
}

void Text::createTexture(const TextInfo &info)
{
    font_ = TTF_OpenFont(info.fontPath, info.fontSize);
    if (!font_) {
        TY_CORE_ERROR("Open font failed: {}", TTF_GetError());
        return;
    }
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font_, info.text, info.color);
    if (!surface) {
        TY_CORE_ERROR("Create text surface failed: {}", TTF_GetError());
        return;
    }
    texture = std::unique_ptr<SDL_Texture,TextureDeleter>(SDL_CreateTextureFromSurface(info.renderer, surface));
    if (!texture) {
        TY_CORE_ERROR("Create text texture failed: {}", SDL_GetError());
        return;
    }
    size.w = surface->w;
    size.h = surface->h;
    SDL_FreeSurface(surface);
    TTF_CloseFont(font_);
}

} // namespace tysm
