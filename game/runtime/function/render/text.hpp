#pragma once

#include <SDL_pixels.h>

#include "./../../core/log/log_system.hpp"
#include "./../framework/object.hpp"
#include "SDL2/SDL.h"
#include "SDL_ttf.h"
#include "image.hpp"

//std
#include <string>

namespace Tysm {
class Text {
public:
    Text(const char* fontPath, int fontSize, SDL_Renderer*);
    void RenderText(Position* pos, std::string str, SDL_Color fg);
    void setFont(const char* fontPath, int fontSize);
    ~Text();

    int w, h;

private:
    TTF_Font* font;
    SDL_Renderer* m_render;
};
}  // namespace Tysm
