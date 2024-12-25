#pragma once

#include <SDL_render.h>

namespace tysm {
class TyObject {
public:
    TyObject(SDL_Renderer *&renderer);
    ~TyObject();
    void render();

private:
    SDL_Renderer *&renderer;

protected:
    SDL_Texture *texture{nullptr};
    SDL_Rect *srcRect{nullptr};
    SDL_Rect *dstRect{nullptr};
};
} // namespace tysm
