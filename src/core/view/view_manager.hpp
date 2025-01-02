#pragma once

#include <SDL_events.h>
#include <SDL_render.h>
#include <memory>

#include "utils/vec2.hpp"
#include "view/iview.hpp"

namespace tysm {
// 管理视图，同时也负责管理画布
class ViewManager {
public:
    ViewManager(Size canvasSize, SDL_Renderer*& renderer);
    ~ViewManager();
    template <typename T>
    static std::unique_ptr<T> createView(SDL_Renderer *&renderer,
                                         ViewManager &viewManager)
    {
        return std::make_unique<T>(renderer, viewManager);
    }
    void route(std::unique_ptr<IView> view);
    void update(SDL_Event &event);

    // 传入window宽高并计算画布rect
    void setCanvas(int w, int h);
    void draw();
private:
    std::unique_ptr<IView> currentView{nullptr};
    Size canvasSize;      // 画布大小
    SDL_Rect canvasRect;// 画布渲染目标rect
    SDL_Renderer *&renderer; // 大家怎么都有renderer
    SDL_Texture* canvas{nullptr};
};
} // namespace tysm
