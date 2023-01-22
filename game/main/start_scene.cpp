#include "start_scene.hpp"

#include "function/framework/object.hpp"
#include "function/ui/ui_text.hpp"

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
    text_pos.x = 0;
    text_pos.y = 0;

}

// write by user
void StartScene::start()
{
    setStaticBg("resources/tianyi (Large).png");
    titleStart();
    // https://www.bilibili.com/festival/VSF2023live?bvid=BV1sx4y1g7Hh
    // 真的很可爱的曲子 请务必要听一听！(～￣▽￣)～
}

void StartScene::run()
{
    m_render_system->draw(&objects);
}

void StartScene::titleStart()
{
    text_pos.x = (m_window_w / 3) + 50;
    text_pos.y = m_window_h / 4;
    title = new Tysm::UI_Text(
        &text_pos, "resources/fonts/SourceHanSansCN-Normal.otf", 80, "你好，Tysm Engine。",
        {255, 255, 255, 255}, m_render_system->getRenderer());
    if (!title) {
        TY_ERROR("Create Text FAIL!!!");
    }
    title->name = "title";
    addObj(title);
}

// 1.create object in start function -> 2.add obj to objs

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
    background = new Tysm::UI_Img(&pos, filePath, m_window_w, m_window_h,
                                  m_render_system->getRenderer());
    int act_h = calBgWidHei(m_window_w)[1];
    pos.y = calPos(act_h)[1];
    background = new Tysm::UI_Img(&pos, filePath, m_window_w, act_h,
                                  m_render_system->getRenderer());
    background->name = "bg";
    // background->position = pos;
    addObj(background);
}

void StartScene::setDynamicBg() {}

bool StartScene::reCreateScene(int act_w, int act_h)
{
    if (m_window_w != act_w || m_window_h != act_h) {
        m_window_w = act_w;
        m_window_h = act_h;
        start();
        return true;
    } else {
        return false;
    }
}

std::array<int, 2> StartScene::calBgWidHei(int w)
{
    float ratio = background->calRatio();
    float h = w / ratio;
    return std::array<int, 2>{w, (int) h};
}

std::array<int, 2> StartScene::calPos(int img_h)
{
    int h = m_window_h - img_h;
    return std::array<int, 2>{0, h / 2};
}
}  // namespace Tysm_Game
