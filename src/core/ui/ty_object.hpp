#pragma once

#include <SDL_render.h>

namespace tysm {
class TyObject {
public:
    explicit TyObject(SDL_Renderer *&renderer);
    ~TyObject();
    void render();

private:
    SDL_Renderer *&renderer;

protected:
    SDL_Rect* dstRect{nullptr};
    SDL_Texture *texture{nullptr};
};
} // namespace tysm
