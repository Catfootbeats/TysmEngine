#pragma once

#include "./../framework/object.hpp"
#include "./../../core/log/log_system.hpp"
#include "SDL2/SDL.h"


//std
#include <iostream>
#include <vector>

namespace Tysm {

struct RenderInfo {
    std::vector<Ty_Object*> render_object;
};

class RenderSystem {
public:
    RenderSystem(SDL_Window*);
    ~RenderSystem();
    void init();
    SDL_Renderer* getRenderer();
    //traversal all Ty_Object and show on the screen
    void present(RenderInfo*);
    void clear();

private:
    SDL_Renderer* m_render;
};
}  // namespace Tysm
