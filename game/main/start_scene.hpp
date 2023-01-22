#pragma once

#include "function/framework/scene.hpp"
#include "function/render/render_system.hpp"
#include "function/ui/img.hpp"
#include "function/ui/ui_text.hpp"

//std
#include <string.h>

#include <algorithm>
#include <array>

namespace Tysm_Game {
class StartScene {
public:
    StartScene(Tysm::RenderSystem*, int window_w, int window_h);
    ~StartScene();
    void start();
    void run();
    void titleStart();
    // Check and reCreate Scene
    bool reCreateScene(int act_w, int act_h);

    // TODO move to scene class
    std::vector<Tysm::Ty_Object*> getObjs();

private:
    Tysm::RenderSystem* m_render_system{nullptr};
    Tysm::UI_Img* background{nullptr};
    Tysm::UI_Text* title{nullptr};
    int m_window_w, m_window_h;
    Tysm::Position pos;
    Tysm::Position text_pos;
    std::vector<Tysm::Ty_Object*> objects;

    // TODO move to scene class
    void addObj(Tysm::Ty_Object*);
    void rmObjByName(std::string);
    Tysm::Ty_Object* findObjByName(std::string);
    void setStaticBg(const char*);
    void setDynamicBg();
    std::array<int, 2> calBgWidHei(int w);
    std::array<int, 2> calPos(int img_h);
};
}  // namespace Tysm_Game
