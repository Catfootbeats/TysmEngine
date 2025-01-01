#include "view_base.hpp"

#include "log.hpp"
#include "view/view_manager.hpp"

namespace tysm {
ViewBase::ViewBase(SDL_Renderer *&renderer, ViewManager &viewManager)
    : m_renderer(renderer), m_viewManager(viewManager)
{
}

ViewBase::~ViewBase()
{
    close();
}

void ViewBase::object(std::vector<TyObject *> objs)
{
    for (int i = 0; i < objs.size(); i++) {
        nameMap[objs[i]->name] = i;
        TY_CORE_INFO(objs[i]->name);
    }
    m_objects = objs;
}

TyObject *ViewBase::findObjectByName(const char *name)
{
    return m_objects[nameMap[name]];
}

void ViewBase::removeObjectByName(const char *name)
{
    if (nameMap.contains(name)) {
        delete m_objects[nameMap[name]];
        m_objects.erase(m_objects.begin() + nameMap[name]);
        m_objects.shrink_to_fit();
        for (auto it = nameMap.find(name); it != nameMap.end(); ++it) {
            it->second -= 1;
        }
        nameMap.erase(name);
    }
}

void ViewBase::addObject(TyObject *object)
{
    m_objects.push_back(object);
    nameMap[object->name] = m_objects.size() - 1;
}

void ViewBase::updateObject(SDL_Event &e, CanvasData &canvasData)
{
    for (auto object : m_objects) {
        object->update(e, canvasData);
    }
}

void ViewBase::close()
{
    for (int i = 0; i < m_objects.size(); ++i) {
        delete m_objects[i];
    }
    m_objects.clear();
}

void ViewBase::show(CanvasData &canvasData)
{
    for (auto &object : m_objects)
        object->render(canvasData);
}
} // namespace tysm
