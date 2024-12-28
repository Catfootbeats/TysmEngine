#include "view_manager.hpp"

#include "log.hpp"

namespace tysm {
ViewManager::ViewManager() = default;

void ViewManager::route(std::unique_ptr<IView> view)
{
    //TODO: 异常处理
    currentView = std::move(view);
    TY_CORE_INFO("Route view success");
}

void ViewManager::update(SDL_Event& event)
{
    if (currentView == nullptr) {
        TY_CORE_WARN("Undefined View");
        return;
    }
    currentView->update(event);
}


void ViewManager::show()
{
    if (currentView == nullptr) {
        TY_ERROR("Undefined View");
        return;
    }
    currentView->show();
}

void ViewManager::quit()
{
    currentView.reset();
}


} // namespace tysm
