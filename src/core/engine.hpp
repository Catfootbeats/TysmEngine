#pragma once

#include "utils/timer.hpp"
#include "view/view_manager.hpp"
#include <SDL_events.h>
#include <SDL_render.h>

namespace tysm {
class Engine {
public:
    Engine();
    ~Engine();
    void run();

private:
    SDL_Event e;
    SDL_Window *mainWindow{nullptr};
    SDL_Renderer *renderer{nullptr};
    SDL_Texture *texture{nullptr};

    std::unique_ptr<ViewManager> viewManager{nullptr};

    bool isQuit{false};
    int FRAMES_PER_SECOND{60};
    //跟踪当前帧的帧计数器
    int frame = 0;
    //是否限制帧率
    bool fpsLimit = true;
    //帧率调节器
    Timer fps;
};

} // namespace tysm
