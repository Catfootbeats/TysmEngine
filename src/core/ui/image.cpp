#include "image.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"
#include <SDL_image.h>

namespace tysm {
Image::Image(SDL_Renderer *&renderer, const char *path) : TyObject(renderer)
{
    texture = IMG_LoadTexture(renderer, path);
    if (!texture)
        TY_CORE_ERROR(IMG_GetError());
}
} // namespace tysm
