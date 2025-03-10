#include "ty_object.hpp"

#include "config.hpp"
#include "log.hpp"
#include "utils/vec2.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>

namespace tysm {
TyObject::TyObject(SDL_Renderer *&renderer,
                   const char *name,
                   const Position pos,
                   const float scale)
    : name(name), pos(pos), scale(scale), renderer(renderer)
{ //子类记得给size赋值呀 ^_^
}

TyObject::TyObject(SDL_Renderer *&renderer,
                   const char *name,
                   const Position pos,
                   const Size size)
    : name(name), pos(pos), size(size), renderer(renderer)
{
}

TyObject::~TyObject()
{
    TY_CORE_INFO("{} removed", name);
}

void TyObject::draw(SDL_Texture *canvas)
{
    if (scale == -1) {
        SDL_RenderCopy(renderer, texture.get(), nullptr, nullptr);
        return;
    }
    dstRect = SDL_Rect{pos.x * UI_SCALE, pos.y * UI_SCALE, size.w * UI_SCALE,
                       size.h * UI_SCALE};
    SDL_RenderCopy(renderer, texture.get(), nullptr, &dstRect);
}
} // namespace tysm
