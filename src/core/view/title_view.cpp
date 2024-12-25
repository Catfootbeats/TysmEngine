#include "title_view.hpp"
#include "ui/image.hpp"
#include <SDL_ttf.h>

namespace tysm {
TitleView::TitleView(SDL_Renderer *&renderer)
    : ViewBase(renderer)
    , titleFont(TTF_OpenFont("res/fonts/SourceHanSansCN-Bold.otf", 24))
    , background({renderer, "res/tianyi.png"})
    //, title(renderer, titleFont, "hello, tysm !!!!!",{255,255,255})
{
    m_objects.push_back(background);
    //m_objects.push_back(title);
}

} // namespace tysm
