#include "image.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"
#include <SDL_image.h>

namespace tysm {
Image::Image(SDL_Renderer *&renderer,
             const char *path,
             Position pos,
             float size)
    : TyObject(renderer)
{
    texture = IMG_LoadTexture(renderer, path);
    if (!texture)
        TY_CORE_ERROR(IMG_GetError());
    if (size != 0) {
        int width, height;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
        dstRect = new SDL_Rect{pos.x, pos.y, static_cast<int>(width * size),
                               static_cast<int>(height * size)};
    }
}
} // namespace tysm
