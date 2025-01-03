#pragma once

#include "ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_render.h>

namespace tysm {
struct ImageInfo {
    SDL_Renderer *&renderer;
    const char *name{};
    const char *path{};
    Position pos = {0, 0};
    float size = 1;
};
class Image final : public TyObject {
public:
    explicit Image(const ImageInfo &);

    void setImage(const char *path);
private:
    void createTexture(const char *path,SDL_Renderer*&renderer);
};
} // namespace tysm
