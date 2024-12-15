#pragma once

#include <SDL.h>

namespace tysm {
class Engine {
public:
    Engine();
    ~Engine();
    void run();

private:
    SDL_Surface *mainSurface{nullptr};
    SDL_Event mainEvent;
    SDL_Window *mainWindow{nullptr};

    bool isQuit{false};
};

} // namespace tysm
