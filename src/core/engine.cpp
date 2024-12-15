#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_keycode.h>
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
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    TY_CORE_INFO("SDL init.");

    TyWindowCreateInfo windowInfo;
    WindowManager::createWindow(mainWindow, windowInfo);
    RendererManager::initRenderer(renderer, mainWindow);
    viewManager.route(VIEW::DIALOG_VIEW);
    // 初始化页面管理器，注册页面

    texture = IMG_LoadTexture(renderer, "res/tianyi.png");
    if (!texture) {
        TY_CORE_ERROR(IMG_GetError());
    }
}

Engine::~Engine()
{
    RendererManager::destroyRenderer(renderer);
    SDL_Quit();
    TY_CORE_INFO("Tysm close.");
}

void Engine::run()
{
    while (!isQuit) {
        EventManager::pollEvent(mainEvent, isQuit);
        // Event
        // Update Logic
        // Manager View
        // Render
        SDL_RenderClear(renderer);
        // view copy
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }
}

} // namespace tysm
