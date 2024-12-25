#include "ty_object.hpp"

namespace tysm{
void TyObject::render(){
SDL_RenderCopy(renderer, texture, srcRect, dstRect);}
}
