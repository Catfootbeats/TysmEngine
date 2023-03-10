#pragma once

#include "ui.hpp"

namespace Tysm {
class UI_Img : public Ty_Object {
public:
    int width, height;
    Image* background{nullptr};
    float calRatio();
    void show();

    UI_Img(Position* position,
           const char* filePath,
           int width,
           int height,
           SDL_Renderer* renderer);
    ;
    ~UI_Img();
};
}  // namespace Tysm
