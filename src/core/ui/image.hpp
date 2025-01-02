#pragma once

#include "ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_render.h>

namespace tysm {
struct ImageInfo {
    SDL_Renderer *&renderer;
    const char *name;
    const char *path;
    Position pos = {0, 0};
    float size = 1;
};
class Image : public TyObject {
public:
    Image(ImageInfo);
    ~Image() = default;
};
} // namespace tysm
