#pragma once
#include "SDL2/SDL.h"
#include "./../../core/log/log_system.hpp"

//std
#include <array>

namespace Tysm {
class WindowSystem {
public:
    WindowSystem() = default;
    ~WindowSystem();
    void init();
    void pollEvents() const;
    bool shouldClose() const;
    void setTitle(const char* title);
    SDL_Window* getWindow() const;
    std::array<int, 2> getWindowSize() const;
    };
}