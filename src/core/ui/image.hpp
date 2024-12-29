#pragma once

#include "ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_render.h>

namespace tysm {
class Image : public TyObject {
public:
    Image(SDL_Renderer *&renderer,
          const char *path,
          Position pos = {0, 0},
          float size = 0.5);
    ~Image() = default;
};
} // namespace tysm
