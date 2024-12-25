#pragma once

#include "ty_object.hpp"
#include <SDL_render.h>

namespace tysm {
class Image : public TyObject {
public:
    Image(SDL_Renderer *&renderer, const char *path);
    ~Image() = default;
};
} // namespace tysm
