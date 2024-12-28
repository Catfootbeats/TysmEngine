#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <SDL_video.h>

#include "engine.hpp"
#include "log.hpp"
#include "render/renderer_manager.hpp"
#include "render/window_manager.hpp"
#include "view/title_view.hpp"

namespace tysm {
Engine::Engine()
{
    Log::Init();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Quit();
        TY_CORE_ERROR("Error initializing SDL:", SDL_GetError());
        return;
    }

    if (TTF_Init() < 0) {
        SDL_Quit();
        TY_CORE_ERROR("Error initializing TTF:", TTF_GetError());
        return;
    }

    TyWindowCreateInfo windowInfo;
    windowInfo.can_resize = true;
    WindowManager::createWindow(mainWindow, windowInfo);
    RendererManager::initRenderer(renderer, mainWindow);
    WindowManager::setWindowMinSize(mainWindow,800,600);
    viewManager.route(
        ViewManager::createView<TitleView>(renderer, viewManager));
}

Engine::~Engine()
{
    viewManager.quit();
    RendererManager::destroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    TY_CORE_INFO("Tysm closed");
}

void Engine::run()
{
    while (!isQuit) {
        // Event
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                isQuit = true;
            if (e.type == SDL_KEYDOWN)
                if ((SDL_GetModState() & KMOD_ALT) && e.key.keysym.sym == SDLK_RETURN)
                    WindowManager::setWindowedOrFullDesktop(mainWindow);
            if (e.type == SDL_WINDOWEVENT) {
                // if ((e.window.event == SDL_WINDOWEVENT_MAXIMIZED)) {
                //     TY_CORE_INFO(WindowManager::getIsFullDesktop(mainWindow));
                //     WindowManager::setWindowedOrFullDesktop(mainWindow);
                // }
                if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
                    // 窗口大小改变时，重新设置渲染器的大小
                    SDL_RenderSetLogicalSize(renderer, e.window.data1,
                                             e.window.data2);
                    //TODO: 重新设置窗口大小以符合画布比例
                }
            }

            viewManager.update(e);
        }
        // Render
        SDL_RenderClear(renderer);
        viewManager.show();
        SDL_RenderPresent(renderer);
        //FPS Limitation
        frame++;
        if (fpsLimit && fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {
            SDL_Delay(1000 / FRAMES_PER_SECOND - fps.get_ticks());
        }
    }
}

} // namespace tysm
