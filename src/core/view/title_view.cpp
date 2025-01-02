#include "title_view.hpp"

#include "log.hpp"
#include "ui/button.hpp"
#include "ui/image.hpp"
#include "ui/text.hpp"
#include "view/view_manager.hpp"
#include <SDL_ttf.h>

namespace tysm {
TitleView::TitleView(SDL_Renderer *&renderer, ViewManager &viewManager)
    : ViewBase(renderer, viewManager)
{
    // user
    titleFont = TTF_OpenFont("res/fonts/SourceHanSansCN-Bold.otf", 144);
    object({new Image({.renderer = renderer,
                       .name = "bg",
                       .path = "res/tianyi.png",
                        .size=-1}),
            new Text({.renderer = renderer,
                      .name = "title",
                      .font = titleFont,
                      .text = "你好, tysm !!!!!",
                      .pos = {30, 100}}),
            new Button({.renderer = renderer,
                        .name = "mybutton",
                        .text = "我是一个按钮哼哼哼啊啊啊啊啊啊",
                        .font = titleFont,
                        .bgColor = {255, 255, 255, 255},
                        .borderColor = {0, 0, 0, 255}})});
    findObjectByName("mybutton")->bindOnClick([this] {
    });
}
TitleView::~TitleView()
{
    TTF_CloseFont(titleFont);
    close();
}

void TitleView::update(SDL_Event &event, SDL_Rect &canvasData)
{
    updateObject(event, canvasData);

    // user
    if (event.type == SDL_KEYDOWN)
        if (event.key.keysym.sym == SDLK_SPACE) {
        }
}

} // namespace tysm
