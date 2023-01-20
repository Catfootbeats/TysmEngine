#pragma once

#include "./../../core/log/log_system.hpp"
#include "./../framework/object.hpp"
#include "SDL2/SDL.h"
#include "SDL_image.h"

//std
#include <iostream>
#include <vector>

namespace Tysm {

// struct RenderInfo {
//     std::vector<Ty_Object*> render_object;
// };

class RenderSystem {
public:
    RenderSystem(SDL_Window*);
    ~RenderSystem();
    void init();
    SDL_Renderer* getRenderer();
    void reCreateRender(SDL_Window*);
    //traversal all Ty_Object and show on the screen
    void draw(std::vector<Ty_Object*>* objs);
    void renderImg(const char*);
    void clear();
    void present();

private:
    SDL_Renderer* m_render;
};
}  // namespace Tysm
