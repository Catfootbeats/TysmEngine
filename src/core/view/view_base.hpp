#pragma once

#include <SDL_render.h>
#include <vector>

#include "ui/ty_object.hpp"
#include "view/iview.hpp"
#include "view/view_manager.hpp"

namespace tysm {
class ViewBase : public IView {
public:
    ViewBase(SDL_Renderer *&renderer, ViewManager &viewManager);
    ~ViewBase() override;
    void close();
    void show(CanvasData canvasData) final;

protected:
    SDL_Renderer *&m_renderer;
    ViewManager &m_viewManager;
    std::vector<TyObject *> m_objects;
};
} // namespace tysm
