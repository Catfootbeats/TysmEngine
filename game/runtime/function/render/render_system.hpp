#pragma once

#include "SDL2/SDL.h"

//std
#include <iostream>
#include <vector>

namespace Tysm {

class RenderSystem {
public:
    RenderSystem(SDL_Window*);
    ~RenderSystem();
    void init();
    SDL_Renderer* getRenderer();
    //traversal all Ty_Object and show on the screen
    void present();

private:
    SDL_Renderer* m_render;
};
}  // namespace Tysm
