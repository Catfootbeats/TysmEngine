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
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    TY_CORE_INFO("SDL init.");

    TyWindowCreateInfo windowInfo;
    WindowManager::createWindow(mainWindow, windowInfo);
    RendererManager::initRenderer(renderer, mainWindow);

    viewManager.route(ViewManager::createView<TitleView>(renderer));
    // TODO: 初始化页面管理器，注册页面

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
        SDL_RenderClear(renderer);
        // Event
        // Update Logic
        // Manager View
        viewManager.show(renderer);
        // Render
        SDL_RenderPresent(renderer);

        //FPS Limitation
        frame++;
        //如果我们需要限制帧率
        if (fpsLimit == true && fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {
            //休眠一段时间，时长为当前帧的剩余时间。
            SDL_Delay(1000 / FRAMES_PER_SECOND - fps.get_ticks());
        }
    }
}

} // namespace tysm
