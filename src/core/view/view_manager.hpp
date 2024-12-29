#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <memory>

#include "utils/canvas_data.hpp"
#include "utils/vec2.hpp"
#include "view/iview.hpp"

namespace tysm {
class ViewManager {
public:
    // 传入一个宽高比用来确定画布大小，但是宽高比并不是实际渲染分辨率
    ViewManager(Size canvasRatio = {1920, 1080});
    template <typename T>
    static std::unique_ptr<T> createView(SDL_Renderer *&renderer,
                                         ViewManager &viewManager)
    {
        return std::make_unique<T>(renderer, viewManager);
    }
    void route(std::unique_ptr<IView> view);
    void update(SDL_Event &event);
    // 传入window宽高并计算画布实际大小
    void setCanvas(int w, int h);
    void quit();
    void show();

private:
    std::unique_ptr<IView> currentView{nullptr};
    // 画布确保显示内容完整，可能会出现黑边 (其实压根没什么画布，只是规定一个渲染范围)
    CanvasData canvasData; // 实际的画布大小
    Size canvasRatio;      // w/h 画布的宽高比
};
} // namespace tysm
