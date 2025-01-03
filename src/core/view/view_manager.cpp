#include "view_manager.hpp"

#include "log.hpp"

namespace tysm {
ViewManager::ViewManager(Size canvasSize, SDL_Renderer *&renderer)
    : canvasSize(canvasSize), renderer(renderer)
{
    canvas =
        SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                          SDL_TEXTUREACCESS_TARGET | SDL_TEXTUREACCESS_STATIC,
                          canvasSize.w, canvasSize.h);
}

ViewManager::~ViewManager()
{
    currentView.reset();
}


void ViewManager::route(std::unique_ptr<IView> view)
{
    //TODO: 异常处理
    currentView = std::move(view);
    TY_CORE_INFO("Route view success");
}

void ViewManager::update(SDL_Event &event, SDL_Window *&window)
{
    if (currentView == nullptr) {
        TY_CORE_WARN("Undefined View");
        return;
    }
    currentView->update(event, canvasRect, window);
}

//计算画布要在屏幕上渲染的位置
//通过传入的窗口大小
void ViewManager::setCanvas(int w, int h)
{
    if ((float) w / h == (float) canvasSize.w / canvasSize.h) {
        canvasRect.w = w;
        canvasRect.h = h;
        canvasRect.x = 0;
        canvasRect.y = 0;
        return;
    }

    if ((float) w / h > (float) canvasSize.w / canvasSize.h) {
        canvasRect.h = h;
        canvasRect.w =
            static_cast<int>(h * ((float) canvasSize.w / canvasSize.h));
        canvasRect.x = static_cast<int>(w - canvasRect.w) / 2;
        canvasRect.y = 0;
        return;
    }

    if ((float) w / h < (float) canvasSize.w / canvasSize.h) {
        canvasRect.w = w;
        canvasRect.h =
            static_cast<int>(w * ((float) canvasSize.h / canvasSize.w));
        canvasRect.x = 0;
        canvasRect.y = static_cast<int>(h - canvasRect.h) / 2;
        return;
    }
}

// 把图形绘制到画布上
void ViewManager::draw()
{
    if (currentView == nullptr) {
        TY_CORE_ERROR("Undefined View");
        return;
    }
    SDL_SetRenderTarget(renderer,canvas);
    SDL_RenderClear(renderer);
    currentView->draw(canvas);
    SDL_SetRenderTarget(renderer,nullptr);
    SDL_RenderCopy(renderer,canvas,nullptr,&canvasRect);
    // step1 在canvas上面绘画
    // step2 将canvas上的内容呈现出来
}
} // namespace tysm
