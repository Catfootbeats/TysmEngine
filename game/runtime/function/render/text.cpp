#include "text.hpp"

#include <SDL_ttf.h>

namespace Tysm {
Text::Text(const char* fontPath, int fontSize, SDL_Renderer* render)
{
    font = TTF_OpenFont(fontPath, fontSize);
    m_render = render;
}

Text::~Text()
{
    TTF_CloseFont(font);
}
}  // namespace Tysm
