#include "start_scene.hpp"

namespace Tysm {
std::vector<Ty_Object*> StartScene::getObjs()
{
    return objects;
}

void StartScene::addObj(Ty_Object* obj)
{
    objects.push_back(obj);
}

void StartScene::rmObjByName(std::string str)
{
    auto iter =
        std::find_if(objects.begin(), objects.end(),
                     [&str](const Ty_Object* obj) { return obj->name == str; });
    if (iter != objects.end()) {
        objects.erase(iter);
    }
}

Ty_Object* StartScene::findObjByName(std::string str)
{
    auto iter = std::find_if(objects.begin(), objects.end(), [&str](const Ty_Object* obj)->bool {return obj->name == str;});
    return objects[std::distance(objects.begin(), iter)];
}

void StartScene::setStaticBg()
{

}

void StartScene::setDynamicBg()
{

}

}