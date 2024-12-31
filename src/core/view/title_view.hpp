#pragma once
#include "utils/canvas_data.hpp"
#include "view_base.hpp"
#include "view_manager.hpp"

#include <SDL2/SDL_ttf.h>
#include <SDL_render.h>
namespace tysm {

class TitleView final : public ViewBase {
public:
    explicit TitleView(SDL_Renderer *&renderer, ViewManager &viewManager);
    ~TitleView() override;
    void update(SDL_Event &event, CanvasData &canvasData) override;

private:
    TTF_Font *titleFont;
};

} // namespace tysm
