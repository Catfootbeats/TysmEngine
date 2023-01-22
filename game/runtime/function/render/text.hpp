#pragma once

#include "./../framework/object.hpp"
#include "SDL2/SDL.h"
#include "SDL_ttf.h"

//std
#include <string>

namespace Tysm {
class Text {
public:
    Text(const char* fontPath, int fontSize, SDL_Renderer*);
    void RenderText(std::string str);
    void setFont(const char* fontPath);
    ~Text();

private:
    TTF_Font* font;
    SDL_Renderer* m_render;
};
}  // namespace Tysm
