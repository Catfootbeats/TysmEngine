#pragma once

#include <SDL_render.h>
#include <map>
#include <vector>

#include "ui/ty_object.hpp"
#include "view/iview.hpp"
#include "view/view_manager.hpp"

namespace tysm {
class ViewBase : public IView {
public:
    ViewBase(SDL_Renderer *&renderer, ViewManager &viewManager);
    ~ViewBase() override;
    void close();
    void show(CanvasData &canvasData) final;

protected:
    SDL_Renderer *&m_renderer;
    ViewManager &m_viewManager;
    void object(std::vector<TyObject *>);
    TyObject *findObjectByName(const char *name);
    void removeObjectByName(const char *name);
    void addObject(TyObject *object);
    void updateObject(SDL_Event &e, CanvasData &canvasData);

private:
    // 维护一个名称和下标的键值对用来查找对象
    std::map<const char *, int> nameMap;
    std::vector<TyObject *> m_objects;
};
} // namespace tysm
