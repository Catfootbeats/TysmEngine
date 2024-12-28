#include "ui/text.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"

#include <SDL_render.h>
#include <SDL_ttf.h>

namespace tysm {
/*
如果size是0 则铺满屏幕（真的有人会把文字铺满屏幕吗）
*/
Text::Text(SDL_Renderer *&renderer,
           TTF_Font *font,
           const char *text,
           SDL_Color color,
           Position pos,
           float size)
    : TyObject(renderer)
{
    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, text, color);
    if (!surface) {
        TY_CORE_ERROR("Create text surface failed", SDL_GetError());
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        TY_CORE_ERROR("Create text texture failed", TTF_GetError());
        return;
    }
    if (size != 0)
        dstRect =
            new SDL_Rect{pos.x, pos.y, static_cast<int>(surface->w * size),
                         static_cast<int>(surface->h * size)};
    SDL_FreeSurface(surface);
}
} // namespace tysm
