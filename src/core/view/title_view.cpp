#include "title_view.hpp"
#include "test/test_view.hpp"
#include "ui/image.hpp"
#include "ui/text.hpp"
#include "view/view_manager.hpp"
#include <SDL_ttf.h>

namespace tysm {
TitleView::TitleView(SDL_Renderer *&renderer, ViewManager &viewManager)
    : ViewBase(renderer, viewManager)
{
    titleFont = TTF_OpenFont("res/fonts/SourceHanSansCN-Bold.otf", 72);
    m_objects.push_back(new Image{renderer, "res/tianyi.png", {0, 0}, 1.0});
    m_objects.push_back(new Text{renderer, titleFont, "你好, tysm !!!!!"});
}
TitleView::~TitleView()
{
    TTF_CloseFont(titleFont);
    close();
}

void TitleView::update(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
        if (event.key.keysym.sym == SDLK_SPACE)
            m_viewManager.route(
                ViewManager::createView<TestView>(m_renderer, m_viewManager));
}

} // namespace tysm
