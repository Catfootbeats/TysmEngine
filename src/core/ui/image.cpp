#include "image.hpp"
#include "log.hpp"
#include "ui/ty_object.hpp"
#include <SDL_image.h>

namespace tysm {
// pos是一个长和宽的占比
Image::Image(const ImageInfo &info)
    : TyObject(info.renderer, info.name, info.pos, info.size)
{
    createTexture(info.path,info.renderer);
}

void Image::setImage(const char *path)
{
    createTexture(path,renderer);
}

void Image::createTexture(const char *path, SDL_Renderer *&renderer)
{
    SDL_DestroyTexture(texture);
    texture = IMG_LoadTexture(renderer, path);
    if (!texture) {
        TY_CORE_ERROR(IMG_GetError());
        return;
    }
    int width, height;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    size.w = width;
    size.h = height;
}

} // namespace tysm
