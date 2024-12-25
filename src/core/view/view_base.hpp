#pragma once
#include <SDL_render.h>
#include <vector>

#include <ui/ty_object.hpp>

namespace tysm {
class ViewBase {
public:
    ViewBase(SDL_Renderer *&renderer);
    ~ViewBase() = default;
    void show();

protected:
    SDL_Renderer *&m_renderer;
    std::vector<TyObject> m_objects;
};
} // namespace tysm
