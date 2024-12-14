#include <SDL_error.h>
#include <SDL_video.h>
#include <cstdio>

#include "engine.hpp"
#include "log.hpp"

namespace tysm {
Engine::Engine()
{
    log_init();
    if (sdl_init())
        close();
    if (creat_window())
        close();
}

Engine::~Engine()
{
    close();
}

void Engine::run()
{
    std::getchar();
}

void Engine::log_init()
{
#ifdef DEBUG
    tysm::Log::Init();
#endif // DEBUG
    TY_CORE_INFO("Log load.");
}

bool Engine::sdl_init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        TY_CORE_ERROR("Error initializing SDL:", SDL_GetError());
        std::getchar();
        return true;
    }
    TY_CORE_INFO("SDL init");
    return false;
}
bool Engine::creat_window()
{
    // TODO: custom window info
    window =
        SDL_CreateWindow("tysm", SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

    if (!window) {
        TY_CORE_ERROR("Error creating window:", SDL_GetError());
        std::getchar();
        return true;
    }

    winSurface = SDL_GetWindowSurface(window);
    if (!winSurface) {
        TY_CORE_ERROR("Error getting surface:", SDL_GetError());
        std::getchar();
        return true;
    }

    // Fill the window with a white rectangle
    SDL_FillRect(winSurface, nullptr,
                 SDL_MapRGB(winSurface->format, 255, 255, 255));

    // Update the window display
    SDL_UpdateWindowSurface(window);
    TY_CORE_INFO("Window create");
    return false;
}

void Engine::close()
{
    // Destroy the window. This will also destroy the surface
    SDL_DestroyWindow(window);
    // Quit SDL
    SDL_Quit();
    TY_CORE_INFO("Tysm close");
}

} // namespace tysm
