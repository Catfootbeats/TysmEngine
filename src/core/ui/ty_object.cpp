#include "ty_object.hpp"

namespace tysm {
TyObject::TyObject(SDL_Renderer *&renderer) : renderer(renderer) {}

TyObject::~TyObject()
{
    SDL_DestroyTexture(texture);
}

void TyObject::render()
{
    SDL_RenderCopy(renderer, texture, srcRect, dstRect);
}
} // namespace tysm
