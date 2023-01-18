#pragma once

#include "function/render/render_system.hpp"
#include "function/framework/scene.hpp"
#include "function/ui/img.hpp"


//std
#include <string.h>
#include <array>
#include <algorithm>

namespace Tysm_Game {
class StartScene{
public:
    StartScene(Tysm::RenderSystem*, int window_w,int window_h);
    ~StartScene();
    void start();
    void run();

    // TODO move to scene class
    std::vector<Tysm::Ty_Object*> getObjs();

private:
    Tysm::RenderSystem* m_render_system{nullptr};
    int m_window_w,m_window_h;
    Tysm::Img* background{nullptr};
    Tysm::Position pos;
    std::vector<Tysm::Ty_Object*> objects;

    // TODO move to scene class
    void addObj(Tysm::Ty_Object*);
    void rmObjByName(std::string);
    Tysm::Ty_Object* findObjByName(std::string);
    void setStaticBg(const char*);
    void setDynamicBg();
    std::array<int, 2> calBgWidHei(int w);
};
}  // namespace Tysm_Game