#include "title_view.hpp"
#include "audio/audio.cpp"
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
    setBgm("res/audio/洛天依 - 夏虫.wav");
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
                        .text = "Play",
                        .fontPath = "res/fonts/SourceHanSansCN-Bold.otf",
                        .borderColor = {0, 0, 0, 255}})});
    findObjectByName("myButton")->bindOnLeftClick([this] {
        TY_INFO("on click");
    });
    findObjectByName("myButton")->bindOnFloat([this] {
        findObjectByName("myButton")->setBgColor({255,255,255,255});
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
