#pragma once

#include <SDL.h>

namespace tysm {
class Engine {
public:
    Engine();
    Engine(Engine &&) = default;
    Engine(const Engine &) = default;
    Engine &operator=(Engine &&) = default;
    Engine &operator=(const Engine &) = default;
    ~Engine();
    void run();

private:
    SDL_Surface *winSurface{nullptr};
    SDL_Window *window{nullptr};

    void log_init();
    bool sdl_init();
    bool creat_window();
    void close();
};

} // namespace tysm
