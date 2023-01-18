#include "image.hpp"

namespace Tysm {

Image::Image(Position* position, const char* filePath, int width, int height, SDL_Renderer* renderer)
{
    m_renderer = renderer;
    texture = IMG_LoadTexture(renderer, filePath);
    if (!texture) {
        TY_CORE_FATAL("Load bg fail!");
        TY_CORE_ERROR(IMG_GetError());
    }
    rect.h = height;
    rect.w = width;
    rect.x = position->x;
    rect.y = position->y;
}

void Image::RenderImg()
{
    SDL_RenderCopy(m_renderer, texture, NULL, &rect);
    // TY_CORE_INFO(SDL_GetError());
}

float Image::calRatio()
{
    SDL_QueryTexture(texture, NULL, NULL, &img_w, &img_h);
    float w = (float)img_w;
    return w / img_h;
}

Image::~Image()
{
    SDL_DestroyTexture(texture);
}
}