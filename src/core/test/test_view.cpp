#include "test_view.hpp"

#include "ui/image.hpp"
#include "view/title_view.hpp"
#include "view/view_manager.hpp"
#include <SDL_ttf.h>
#include <memory>

namespace tysm {
TestView::TestView(SDL_Renderer *&renderer, ViewManager &viewManager)
    : ViewBase(renderer, viewManager)
{
    // m_objects.push_back(new Image(
    //     {.renderer = renderer, .path = "res/tianyi_1.png", .size = 1}));
}
TestView::~TestView()
{
    close();
}

void TestView::update(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
        if (event.key.keysym.sym == SDLK_SPACE)
            m_viewManager.route(
                ViewManager::createView<TitleView>(m_renderer, m_viewManager));
}

} // namespace tysm
