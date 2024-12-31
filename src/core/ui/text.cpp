#include "ui/text.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>

namespace tysm {
Text::Text(TextInfo info)
    : TyObject(info.renderer, info.name, info.pos, info.size)
{
    SDL_Surface *surface =
        TTF_RenderUTF8_Blended(info.font, info.text, info.color);
    if (!surface) {
        TY_CORE_ERROR("Create text surface failed", SDL_GetError());
        return;
    }
    texture = SDL_CreateTextureFromSurface(info.renderer, surface);
    if (!texture) {
        TY_CORE_ERROR("Create text texture failed", TTF_GetError());
        return;
    }
    aspectRatio = (float) surface->w / surface->h;
    SDL_FreeSurface(surface);
}
} // namespace tysm
