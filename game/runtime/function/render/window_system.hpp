#pragma once

#include "./../../core/log/log_system.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

//std
#include <array>

namespace Tysm {
struct TyWindowCreateInfo {
    int width{800};
    int height{600};
    const char* title{"Tysm"};
    bool is_fullscreen;
    bool can_Resize;
};

class WindowSystem {
public:
    WindowSystem() = default;
    ~WindowSystem();
    void init(TyWindowCreateInfo createInfo);
    int pollEvents();
    // TODO bool shouldClose() const;
    void setTitle(const char* title);
    void setWindowMinSize(int w, int h);
    void setWindowMaxSize(int w, int h);
    SDL_Window* getWindow() const;
    SDL_Event getEvent();
    std::array<int, 2> getWindowSize() const;
    void setFullDesktop();
    void setIcon(const char* path);

private:
    SDL_Window* m_window{nullptr};
    SDL_Event m_event{0};
    int m_width{0};
    int m_height{0};

    int flags{0};
};
}  // namespace Tysm
