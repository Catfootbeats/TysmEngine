#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_keycode.h>
#include <SDL_video.h>

#include "engine.hpp"
#include "log.hpp"
#include "render/window_manager.hpp"

namespace tysm {
Engine::Engine()
{
    Log::Init();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Quit();
        TY_CORE_ERROR("Error initializing SDL:", SDL_GetError());
        return;
    }
    TY_CORE_INFO("SDL init.");

    TyWindowCreateInfo windowInfo;
    WindowManager::createWindow(mainWindow, windowInfo);
}

Engine::~Engine()
{
    SDL_Quit();
    TY_CORE_INFO("Tysm close.");
}

void Engine::run()
{
    WindowManager::infoMassageBox(mainWindow, "Hello, tysm!");
    while (!isQuit) {
        while (SDL_PollEvent(&mainEvent)) {
            if (mainEvent.type == SDL_QUIT) {
                isQuit = true;
            }
        }
    }
}

} // namespace tysm
