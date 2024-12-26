#pragma once

#include "ui/ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_ttf.h>

namespace tysm {
class Text : public TyObject {
public:
    Text(SDL_Renderer *&renderer,
         TTF_Font *font,
         const char *text,
         SDL_Color color = {0, 0, 0},
         vec2 pos = {0, 0},
         float size = 1.0);
};
} // namespace tysm
