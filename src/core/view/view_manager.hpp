#pragma once

#include <SDL_render.h>
#include <SDL_events.h>
#include <memory>

#include "view/iview.hpp"

namespace tysm {
class ViewManager {
public:
    ViewManager();
    template <typename T>
    static std::unique_ptr<T> createView(SDL_Renderer *&renderer,ViewManager &viewManager)
    {
        return std::make_unique<T>(renderer,viewManager);
    }
    void route(std::unique_ptr<IView> view);
    void update(SDL_Event& event);
    void quit();
    void show();
    float canvasRatio = 1920/1080; // w/h

private:
    std::unique_ptr<IView> currentView{nullptr};
};
} // namespace tysm
