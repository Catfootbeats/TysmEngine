#pragma once

#include "scene.hpp"

namespace Tysm {
class StartScene : Scene {
public:
    std::vector<Ty_Object*> getObjs();
    void addObj(Ty_Object*);
    void rmObj();
    void setStaticBg();
    void setDynamicBg();
private:
    std::vector<Ty_Object*> objects;
};
}