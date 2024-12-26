#include "title_view.hpp"
#include "ui/image.hpp"
#include "ui/text.hpp"
#include <SDL_ttf.h>
#include <memory>

namespace tysm {
TitleView::TitleView(SDL_Renderer *&renderer)
    : ViewBase(renderer)
{
    titleFont = TTF_OpenFont("res/fonts/SourceHanSansCN-Bold.otf", 72);
    m_objects.push_back(new Image{renderer, "res/tianyi.png"});
    m_objects.push_back(new Text{renderer, titleFont,"你好, tysm !!!!!"});
}
TitleView::~TitleView()
{
    TTF_CloseFont(titleFont);
}


} // namespace tysm
