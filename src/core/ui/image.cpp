#include "image.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"
#include <SDL_image.h>

namespace tysm {
// pos是一个长和宽的占比
Image::Image(SDL_Renderer *&renderer,
             const char *path,
             Position pos,
             float size)
    : TyObject(renderer, pos, size)
{
    texture = IMG_LoadTexture(renderer, path);
    if (!texture) {
        TY_CORE_ERROR(IMG_GetError());
        return;
    }
    int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    aspectRatio = (float) width / height;
}
} // namespace tysm
