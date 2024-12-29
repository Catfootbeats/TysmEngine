#include "view_manager.hpp"

#include "log.hpp"

namespace tysm {
ViewManager::ViewManager(Size canvasRatio) : canvasRatio(canvasRatio) {}

void ViewManager::route(std::unique_ptr<IView> view)
{
    //TODO: 异常处理
    currentView = std::move(view);
    TY_CORE_INFO("Route view success");
}

void ViewManager::update(SDL_Event &event)
{
    if (currentView == nullptr) {
        TY_CORE_WARN("Undefined View");
        return;
    }
    currentView->update(event);
}

void ViewManager::setCanvas(int w, int h)
{
    if ((float) w / h == (float) canvasRatio.w / canvasRatio.h) {
        canvasData.w = w;
        canvasData.h = h;
        canvasData.xOffset = 0;
        canvasData.yOffset = 0;
        return;
    }

    if ((float) w / h > (float) canvasRatio.w / canvasRatio.h) {
        canvasData.h = h;
        canvasData.w =
            static_cast<int>(h * ((float) canvasRatio.w / canvasRatio.h));
        canvasData.xOffset = static_cast<int>(w - canvasData.w) / 2;
        canvasData.yOffset = 0;
        return;
    }

    if ((float) w / h < (float) canvasRatio.w / canvasRatio.h) {
        canvasData.w = w;
        canvasData.h =
            static_cast<int>(w * ((float) canvasRatio.h / canvasRatio.w));
        canvasData.xOffset = 0;
        canvasData.yOffset = static_cast<int>(h - canvasData.h) / 2;
        return;
    }
}

void ViewManager::show()
{
    if (currentView == nullptr) {
        TY_CORE_ERROR("Undefined View");
        return;
    }
    currentView->show(canvasData);
}

void ViewManager::quit()
{
    currentView.reset();
}

} // namespace tysm
