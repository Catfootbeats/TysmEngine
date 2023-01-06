#include "window_system.hpp"

#include <SDL_events.h>
#include <SDL_video.h>

#include <array>

namespace Tysm {
WindowSystem::~WindowSystem()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void WindowSystem::init(TyWindowCreateInfo createInfo)
{
    if (createInfo.is_fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN;
    } else {
        flags = SDL_WINDOW_SHOWN;
    }
    m_window = SDL_CreateWindow(createInfo.title, SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, createInfo.width,
                                createInfo.height, flags);
    m_height = createInfo.height;
    m_width = createInfo.width;
    if (!m_window) {
        TY_CORE_FATAL("Create Window Fatal!");
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return;
    }
}

void WindowSystem::setTitle(const char* title)
{
    SDL_SetWindowTitle(m_window, title);
}

SDL_Window* WindowSystem::getWindow() const
{
    return m_window;
}

void WindowSystem::pollEvents() const
{
    SDL_PollEvent(event);
}

std::array<int, 2> WindowSystem::getWindowSize() const
{
    return std::array<int, 2>({m_width, m_height});
}
}  //namespace Tysm
