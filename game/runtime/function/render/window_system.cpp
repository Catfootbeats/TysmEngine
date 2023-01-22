#include "window_system.hpp"

#include <SDL_surface.h>
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
        flags = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN |
                SDL_WINDOW_ALLOW_HIGHDPI;
    } else {
        flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
    }

    if (createInfo.can_Resize) flags = flags | SDL_WINDOW_RESIZABLE;

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
    TY_CORE_INFO("Create Window Succeed!");
}

void WindowSystem::setTitle(const char* title)
{
    SDL_SetWindowTitle(m_window, title);
}

void WindowSystem::setWindowMinSize(int w, int h)
{
    SDL_SetWindowMinimumSize(m_window, w, h);
}

void WindowSystem::setWindowMaxSize(int w, int h)
{
    SDL_SetWindowMaximumSize(m_window, w, h);
}

SDL_Window* WindowSystem::getWindow() const
{
    return m_window;
}

SDL_Event WindowSystem::getEvent()
{
    return m_event;
}

void WindowSystem::setFullDesktop()
{
    SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

int WindowSystem::pollEvents()
{
    return SDL_PollEvent(&m_event);
}

std::array<int, 2> WindowSystem::getWindowSize() const
{
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return std::array<int, 2>({w, h});
}

void WindowSystem::setIcon(const char* path)
{
    SDL_Surface* surface = SDL_LoadBMP(path);
    if (!surface) TY_CORE_FATAL("fatal to set window icon!");
    SDL_SetWindowIcon(m_window, surface);
    SDL_FreeSurface(surface);
}

}  //namespace Tysm
