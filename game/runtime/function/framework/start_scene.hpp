#pragma once

#include "scene.hpp"

//std
#include <string.h>
#include <algorithm>

namespace Tysm {
class StartScene : Scene {
public:
    std::vector<Ty_Object*> getObjs();
    void addObj(Ty_Object*);
    void rmObjByName(std::string);
    Ty_Object* findObjByName(std::string);
    void setStaticBg();
    void setDynamicBg();
private:
    std::vector<Ty_Object*> objects;
};
}