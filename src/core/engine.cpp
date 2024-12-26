#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_video.h>

#include "engine.hpp"
#include "input/event_manager.hpp"
#include "log.hpp"
#include "render/renderer_manager.hpp"
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
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        TY_CORE_WARN("Linear texture filtering not enabled!");

    if (TTF_Init() < 0) {
        SDL_Quit();
        TY_CORE_ERROR("Error initializing TTF:", TTF_GetError());
        return;
    }

    TyWindowCreateInfo windowInfo;
    WindowManager::createWindow(mainWindow, windowInfo);
    RendererManager::initRenderer(renderer, mainWindow);

    viewManager.route(ViewManager::createView<TitleView>(renderer));
}

Engine::~Engine()
{
    RendererManager::destroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    TY_CORE_INFO("Tysm close.");
}

void Engine::run()
{
    while (!isQuit) {
        EventManager::pollEvent(mainEvent, isQuit);
        SDL_RenderClear(renderer);
        // Event
        // Update Logic
        // Manager View
        viewManager.show();
        // Render
        SDL_RenderPresent(renderer);

        //FPS Limitation
        frame++;
        if (fpsLimit == true && fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {
            SDL_Delay(1000 / FRAMES_PER_SECOND - fps.get_ticks());
        }
    }
}

} // namespace tysm
