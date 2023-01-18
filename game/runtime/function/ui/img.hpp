#pragma once

#include "ui.hpp"

namespace Tysm {
class Img : public Ty_Object {
public:

    int width, height;
    Image* background{nullptr};
    float calRatio();
    void show();

    Img(Position* position,
        const char* filePath,
        int width,
        int height,
        SDL_Renderer* renderer);
    ;
};
}