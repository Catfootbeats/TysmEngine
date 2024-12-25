#include "view_manager.hpp"

#include "log.hpp"

namespace tysm {
ViewManager::ViewManager() = default;

void ViewManager::route(std::unique_ptr<ViewBase> view)
{
    currentView = std::move(view);
}
void ViewManager::show() const
{
    if (currentView == nullptr)
        TY_ERROR("Undefined View");
    currentView->show();
}

} // namespace tysm
