#pragma once
#include "SDL2/SDL.h"
#include "./../../core/log/log_system.hpp"

//std
#include <array>

namespace Tysm {
struct TyWindowCreateInfo {
    int width{800};
    int height{600};
    const char* title{"Tysm"};
    bool is_fullscreen;
};

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

private:
    SDL_Window* m_window;
    int m_width;
    int m_height;

    bool m_is_focus_mode;
    };
}