#pragma once

#include "ui/container.hpp"
#include "utils/vec2.hpp"
#include <SDL_pixels.h>
#include <SDL_render.h>
#include <functional>
namespace tysm {

struct onFloatState {
    const char *imgPath = nullptr;
    SDL_Color bgColor = {255, 255, 255, 0};
};

struct ButtonInfo {
    SDL_Renderer *&renderer;
    const char *name;
    PositionScaler pos = {0, 0};
    SizeScaler sizeScaler = {0.3, 0.1};
    const char *text = nullptr;
    const char *imgPath = nullptr;
    SDL_Color bgColor = {255, 255, 255, 0};
    onFloatState onFloatState;
};
class Button : public Container {
public:
    Button(ButtonInfo);
    ~Button() = default;
    void bindOnClick(std::function<void()> func) override;

    void update(SDL_Event &e, CanvasData &canvasData) override;
    void render(CanvasData &canvasData) override;

private:
    int x, y, w, h;
    std::function<void()> onClickFunc;
    bool isFloat(SDL_Event &e, CanvasData &canvasData);
    bool isClick(SDL_Event &e, CanvasData &canvasData);
};
} // namespace tysm
