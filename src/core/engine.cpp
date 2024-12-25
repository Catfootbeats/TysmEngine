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

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 && TTF_Init() < 0) {
        SDL_Quit();
        TTF_Quit();
        TY_CORE_ERROR("Error initializing SDL:", SDL_GetError());
        return;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    TY_CORE_INFO("SDL init.");

    TyWindowCreateInfo windowInfo;
    WindowManager::createWindow(mainWindow, windowInfo);
    RendererManager::initRenderer(renderer, mainWindow);

    viewManager.route(ViewManager::createView<TitleView>(renderer));
    texture = IMG_LoadTexture(renderer, "res/tianyi.png");
    if (!texture) {
        TY_CORE_ERROR(IMG_GetError());
    }
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
