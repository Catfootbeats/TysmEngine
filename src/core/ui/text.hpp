#pragma once

#include "ui/ty_object.hpp"
#include <SDL_ttf.h>

namespace tysm {
class Text : public TyObject {
public:
    Text(SDL_Renderer *&renderer,
         TTF_Font *font,
         const char *text,
         SDL_Color color = {0,0,0});
    ~Text() = default;
};
} // namespace tysm
