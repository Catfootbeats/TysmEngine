#pragma once

#include <SDL_render.h>
#include <map>
#include <vector>

#include "ui/ty_object.hpp"
#include "view/iview.hpp"
#include "view/view_manager.hpp"

#include <SDL_mixer.h>

namespace tysm {
class ViewBase : public IView {
public:
    ViewBase(SDL_Renderer *&renderer, ViewManager &viewManager);
    ~ViewBase() override;
    void close();
    void draw(SDL_Texture *canvas) final;

protected:
    SDL_Renderer *&m_renderer;
    ViewManager &m_viewManager;
    void object(const std::vector<TyObject *> &);
    TyObject *findObjectByName(const char *name);
    void removeObjectByName(const char *name);
    void addObject(TyObject *object);
    void updateObject(SDL_Event &e, SDL_Rect &canvasData, SDL_Window *&window);
    void setBgm(const char * path);

private:
    // 维护一个名称和下标的键值对用来查找对象
    std::map<const char *, int> nameMap;
    std::vector<TyObject *> m_objects;
    std::unique_ptr<Mix_Music, MusicDeleter> bgm{nullptr};
};
} // namespace tysm
