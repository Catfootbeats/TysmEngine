#pragma once
#include "view_base.hpp"
#include "view_manager.hpp"

#include <SDL2/SDL_ttf.h>
#include <SDL_render.h>
namespace tysm {

class TitleView final : public ViewBase {
public:
    explicit TitleView(SDL_Renderer *&renderer, ViewManager &viewManager);
    void update(SDL_Event &event,
                SDL_Rect &canvasRect,
                SDL_Window *&window) override;
};

} // namespace tysm
