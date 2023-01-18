#pragma once

#include "./../framework/object.hpp"
#include "./../../core/log/log_system.hpp"
#include "SDL2/SDL.h"
#include "SDL_image.h"

//std
#include <array>

namespace Tysm {
class Image {
public:
    Image(Position*, const char*, int width, int height, SDL_Renderer*);
    void RenderImg();
    float calRatio();
    // TODO finish Image GetImage Width and Height
    std::array<int, 2> GetImgWidHei();
    ~Image();

private:
    SDL_Renderer* m_renderer;
    SDL_Texture* texture;
    SDL_Rect rect;

    int img_w, img_h;

    };
}