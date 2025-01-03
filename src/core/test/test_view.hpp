#pragma once
#include "view/view_base.hpp"
#include "view/view_manager.hpp"

#include <SDL2/SDL_ttf.h>
#include <SDL_render.h>
namespace tysm {

class TestView final : public ViewBase {
public:
    explicit TestView(SDL_Renderer *&renderer, ViewManager &viewManager);
    ~TestView() override;
    void update(SDL_Event &, SDL_Rect &canvasData, SDL_Window *&window) override;
};

} // namespace tysm
