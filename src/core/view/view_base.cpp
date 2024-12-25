#include "view_base.hpp"

namespace tysm {
ViewBase::ViewBase(SDL_Renderer *&renderer)
    : m_renderer(renderer)
{
}

void ViewBase::show()
{
    for (auto &object : m_objects)
        object.render();
}
} // namespace tysm
