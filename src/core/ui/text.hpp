#pragma once

#include "ui/ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_ttf.h>

namespace tysm {
struct TextInfo {
    SDL_Renderer *&renderer;
    const char *name;
    TTF_Font *font;
    const char *text;
    SDL_Color color = {0, 0, 0};
    PositionScaler pos = {0, 0};
    float size = 0.2;
};
class Text : public TyObject {
public:
    Text(TextInfo);
};
} // namespace tysm
