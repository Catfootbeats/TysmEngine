#pragma once

#include "./../../core/log/log_system.hpp"
#include "SDL2/SDL.h"

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
    void init(TyWindowCreateInfo createInfo);
    void pollEvents() const;
    // bool shouldClose() const;
    void setTitle(const char* title);
    SDL_Window* getWindow() const;
    SDL_Event* getEvent();
    std::array<int, 2> getWindowSize() const;

private:
    SDL_Window* m_window{nullptr};
    SDL_Event* event{nullptr};
    int m_width{0};
    int m_height{0};

    int flags{0};
};
}  // namespace Tysm
