#pragma once

#include "dialog_view.hpp"
#include "title_view.hpp"
#include "view_base.hpp"
#include <SDL_render.h>
#include <memory>
#include <vector>
namespace tysm {
class ViewManager {
public:
    ViewManager();
    template <typename T>
    static std::unique_ptr<T> createView(SDL_Renderer*& renderer)
    {
        return std::make_unique<T>(renderer);
    }
    void route(std::unique_ptr<ViewBase> view);
    void show(SDL_Renderer *&) const;

private:
    std::unique_ptr<ViewBase> currentView;
};
} // namespace tysm
