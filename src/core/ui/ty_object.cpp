#include "ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>

namespace tysm {
TyObject::TyObject(SDL_Renderer *&renderer,
                   const char *name,
                   const Position pos,
                   const float scale)
    : name(name), renderer(renderer), pos(pos), scale(scale)
{//子类记得给size赋值呀 ^_^
}

TyObject::TyObject(SDL_Renderer *&renderer,
                   const char *name,
                   const Position pos,
                   const Size size)
    : name(name), renderer(renderer), pos(pos), size(size)
{
}

TyObject::~TyObject()
{
    if (!dstRect)
        delete dstRect;
    SDL_DestroyTexture(texture);
}

void TyObject::draw(SDL_Texture *canvas)
{
    if (!dstRect)
        delete dstRect;
    dstRect = nullptr;
    if (scale != -1)
        dstRect = new SDL_Rect{pos.x*UI_SCALE, pos.y*UI_SCALE, size.w*UI_SCALE, size.h*UI_SCALE};
    SDL_RenderCopy(renderer, texture, nullptr, dstRect);
}
} // namespace tysm
