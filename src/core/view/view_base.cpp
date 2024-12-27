#include "view_base.hpp"

#include "view/view_manager.hpp"

namespace tysm {
ViewBase::ViewBase(SDL_Renderer *&renderer, ViewManager &viewManager)
    : m_renderer(renderer), m_viewManager(viewManager){}

ViewBase::~ViewBase()
{
     close();
}

void ViewBase::close()
{
    for (int i = 0; i < m_objects.size(); ++i) {
        delete m_objects[i];
    }
    m_objects.clear();
}

void ViewBase::show()
{
    for (auto &object : m_objects)
        object->render();
}
} // namespace tysm
