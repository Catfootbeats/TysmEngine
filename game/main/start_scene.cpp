#include "start_scene.hpp"



namespace Tysm_Game {

StartScene::StartScene(Tysm::RenderSystem* renderSystem,
                       int window_w,
                       int window_h)
{
    m_window_w = window_w;
    m_window_h = window_h;
    m_render_system = renderSystem;
    pos.x = 0;
    pos.y = 0;
}

// write by user
void StartScene::start()
{
    setStaticBg("resources/tianyi.png");
}

void StartScene::run()
{
    m_render_system->draw(&objects);
}


// TODO move to scene class
std::vector<Tysm::Ty_Object*> StartScene::getObjs()
{
    return objects;
}

void StartScene::addObj(Tysm::Ty_Object* obj)
{
    objects.push_back(obj);
}

void StartScene::rmObjByName(std::string str)
{
    auto iter = std::find_if(
        objects.begin(), objects.end(),
        [&str](const Tysm::Ty_Object* obj) { return obj->name == str; });
    if (iter != objects.end()) {
        objects.erase(iter);
    }
}

Tysm::Ty_Object* StartScene::findObjByName(std::string str)
{
    auto iter = std::find_if(objects.begin(), objects.end(),
                             [&str](const Tysm::Ty_Object* obj) -> bool {
                                 return obj->name == str;
                             });
    return objects[std::distance(objects.begin(), iter)];
}

void StartScene::setStaticBg(const char* filePath)
{
    background = new Tysm::Img(&pos, filePath, m_window_w, m_window_h,
                               m_render_system->getRenderer());
    int act_h = calBgWidHei(m_window_w)[1];
    background = new Tysm::Img(&pos, filePath, m_window_w, act_h,
                               m_render_system->getRenderer());
    background->name = "bg";
    // background->position = pos;
    addObj(background);
}

void StartScene::setDynamicBg() {}

std::array<int, 2> StartScene::calBgWidHei(int w)
{
    float ratio = background->calRatio();
    float h = w / ratio;
    return std::array<int, 2>{w,(int)h};
}
}
