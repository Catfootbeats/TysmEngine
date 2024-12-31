#include "ui/button.hpp"

namespace tysm {
Button::Button(ButtonInfo info)
    : Container(info.renderer, info.name, info.pos, info.sizeScaler)
{
}
void Button::bindOnClick(std::function<void()> func)
{
    onClickFunc = func;
}

void Button::update(SDL_Event &e, CanvasData &canvasData)
{
    if (isClick(e, canvasData) && onClickFunc != nullptr)
        onClickFunc();
}

void Button::render(CanvasData &canvasData)
{
    // 这里的xOffset,yOffset是x,y像素点位置
    containerData.xOffset =
        static_cast<int>(canvasData.w * pos.xScaler + canvasData.xOffset);
    containerData.yOffset =
        static_cast<int>(canvasData.h * pos.yScaler + canvasData.yOffset);
    containerData.w = static_cast<int>(canvasData.w * sizeScaler.wScaler);
    containerData.h = static_cast<int>(canvasData.h * sizeScaler.hScaler);
    for (auto &object : children)
        object->render(containerData);
}

bool Button::isFloat(SDL_Event &e, CanvasData &canvasData) {}

bool Button::isClick(SDL_Event &e, CanvasData &canvasData)
{
    return 1;
}
} // namespace tysm
