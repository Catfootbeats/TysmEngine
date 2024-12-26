#include "ui/text.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>

namespace tysm {
Text::Text(SDL_Renderer *&renderer,
           TTF_Font *font,
           const char *text,
           SDL_Color color)
    : TyObject(renderer)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    if (!surface)
        TY_CORE_ERROR(SDL_GetError());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
        TY_CORE_ERROR(TTF_GetError());
    SDL_FreeSurface(surface);
}
} // namespace tysm
