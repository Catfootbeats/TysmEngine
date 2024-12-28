#include "ty_object.hpp"

namespace tysm {
TyObject::TyObject(SDL_Renderer *&renderer) : renderer(renderer) {}

TyObject::~TyObject()
{
    if (!dstRect)
        delete dstRect;
    // move dstRect to render
    SDL_DestroyTexture(texture);

}

void TyObject::render()
{
    SDL_RenderCopy(renderer, texture, nullptr, dstRect);
}
} // namespace tysm
