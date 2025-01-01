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
                       .size = 1.0}),
            new Text({.renderer = renderer,
                      .name = "title",
                      .font = titleFont,
                      .text = "你好, tysm !!!!!",
                      .pos = {0.1, 0.3},
                      .size = 0.5}),
            new Button({.renderer = renderer,
                        .name = "mybutton",
                        .text = "我是一个按钮哼哼哼啊啊啊啊啊啊",
                        .font = titleFont,
                        .bgColor = {255, 255, 255, 255},
                        .borderColor = {0, 0, 0, 255}})});
    findObjectByName("mybutton")->bindOnClick([this] {
        TY_CORE_INFO("哼哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊");
    });
}
TitleView::~TitleView()
{
    TTF_CloseFont(titleFont);
    close();
}

void TitleView::update(SDL_Event &event, CanvasData &canvasData)
{
    updateObject(event, canvasData);

    // user
    if (event.type == SDL_KEYDOWN)
        if (event.key.keysym.sym == SDLK_SPACE) {
            removeObjectByName("title");
            addObject(new Text({.renderer = m_renderer,
                                .name = "title1",
                                .font = titleFont,
                                .text = "你好, tysm !!!!!",
                                .pos = {0.6, 0.3},
                                .size = 0.5}));
        }
}

} // namespace tysm
