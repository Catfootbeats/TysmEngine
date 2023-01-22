#include "text.hpp"

#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_ttf.h>

namespace Tysm {
// every text will referce to a Text object and a font
Text::Text(const char* fontPath, int fontSize, SDL_Renderer* render)
{
    font = TTF_OpenFont(fontPath, fontSize);
    m_render = render;
}

void Text::RenderText(Position* pos, std::string str, SDL_Color fg)
{
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, str.c_str(), fg);
    SDL_Texture* textTexture =
        SDL_CreateTextureFromSurface(m_render, textSurface);
    if (!textTexture) {
        TY_CORE_FATAL("Load bg fail!");
        TY_CORE_ERROR(TTF_GetError());
    }
    w = textSurface->w;
    h = textSurface->h;
    SDL_Rect textRect = {pos->x, pos->y, textSurface->w, textSurface->h};
    SDL_FreeSurface(textSurface);
    SDL_RenderCopy(m_render, textTexture, nullptr, &textRect);
}

void Text::setFont(const char* fontPath, int fontSize)
{
    TTF_CloseFont(font);
    font = TTF_OpenFont(fontPath, fontSize);
}

Text::~Text()
{
    TTF_CloseFont(font);
}
}  // namespace Tysm
