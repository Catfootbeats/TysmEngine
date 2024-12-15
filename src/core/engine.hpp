#pragma once

#include "view/view_manager.hpp"
#include <SDL.h>

namespace tysm {
class Engine {
public:
    Engine();
    ~Engine();
    void run();

private:
    SDL_Event mainEvent;
    SDL_Window *mainWindow{nullptr};
    SDL_Renderer *renderer{nullptr};
    SDL_Texture *texture{nullptr};

    ViewManager viewManager;

    bool isQuit{false};
};

} // namespace tysm
