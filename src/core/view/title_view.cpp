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
    // ui部分的编写
    object({new Image({.renderer = renderer,
                       .name = "bg",
                       .path = "res/tianyi.png",
                       .size = -1}),

            new Text({.renderer = renderer,
                      .name = "title",
                      .fontPath = "res/fonts/SourceHanSansCN-Bold.otf",
                      .text = "你好, tysm !!!!!",
                      .pos = {30, 100}}),

            new Button({.renderer = renderer,
                        .name = "myButton",
                        .size = {1000, 250},
                        .text = "我是一个按钮",
                        .fontPath = "res/fonts/SourceHanSansCN-Bold.otf",
                        .imgPath = "res/homo.png",
                        .borderColor = {0, 0, 0, 255}})});

    findObjectByName("myButton")->bindOnFloat([this] {
        TY_CORE_INFO("哼哼哼啊啊啊啊");
    });
}

void TitleView::update(SDL_Event &event,
                       SDL_Rect &canvasRect,SDL_Window*&window)
{
    updateObject(event, canvasRect,window);

    // user
    // 整个页面的事件处理
    if (event.type == SDL_KEYDOWN)
        if (event.key.keysym.sym == SDLK_SPACE) {
            findObjectByName("bg")->setImage("res/yuzu.png");
            findObjectByName("title")->setText("Ciallo～(∠・ω<)⌒☆");
        }
}

} // namespace tysm
