#pragma once

#include "ui/ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_pixels.h>
#include <SDL_render.h>
namespace tysm {
struct ButtonInfo {
    SDL_Renderer *&renderer;
    const char *name;
    PositionScaler pos = {0, 0};
    SizeScaler size = {0.3, 0.1};
    const char *text = nullptr;
    const char *imgPath = nullptr;
    SDL_Color bgColor = {255, 255, 255, 0};
};
class Button : public TyObject {
public:
    Button(ButtonInfo);
    ~Button() = default;
    void onClick();
    void onFloat();
};
} // namespace tysm
