#pragma once

#include "IView.hpp"
#include "dialog_view.hpp"
#include "title_view.hpp"
#include <SDL_render.h>
#include <memory>
#include <vector>
namespace tysm {
enum VIEW { TITLE_VIEW, DIALOG_VIEW };
class ViewManager {
public:
    ViewManager() = default;
    ~ViewManager() = default;
    void route(VIEW);
    void show(SDL_Renderer *&);

private:
    std::unique_ptr<TitleView> titleView;
    std::unique_ptr<DialogView> dialogView;
    VIEW viewState{VIEW::TITLE_VIEW};
    std::vector<IView *> views;
};
} // namespace tysm
