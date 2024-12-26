#include "ui/text.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>

namespace tysm {
/*
if size == 0, dstRect = nullptr, fill screen
*/
Text::Text(SDL_Renderer *&renderer,
           TTF_Font *font,
           const char *text,
           SDL_Color color,
           vec2 pos,
           float size)
    : TyObject(renderer)
{
    SDL_Surface *surface = TTF_RenderUTF8_Solid(font, text, color);
    if (!surface)
        TY_CORE_ERROR(SDL_GetError());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
        TY_CORE_ERROR(TTF_GetError());
    if (size != 0)
        dstRect =
            new SDL_Rect{pos.x, pos.y, static_cast<int>(surface->w * size),
                         static_cast<int>(surface->h * size)};
    SDL_FreeSurface(surface);
}
} // namespace tysm
