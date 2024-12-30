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

struct WindowEventData {
    SDL_Renderer *renderer;
    ViewManager *vm;
};

int WindowEventFilter(void *userdata, SDL_Event *event)
{
    WindowEventData *data = (WindowEventData *) userdata;
    if (event->type == SDL_WINDOWEVENT) {
        if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
            // 窗口大小改变时，重新设置渲染器的大小
            SDL_RenderSetLogicalSize(data->renderer, event->window.data1,
                                     event->window.data2);
            data->vm->setCanvas(event->window.data1, event->window.data2);
            // Render
            SDL_RenderClear(data->renderer);
            data->vm->show();
            SDL_RenderPresent(data->renderer);
        }
    }
    return 0;
}

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

    // create window and renderer
    TyWindowCreateInfo windowInfo;
    windowInfo.can_resize = true;
    WindowManager::createWindow(mainWindow, windowInfo);
    RendererManager::initRenderer(renderer, mainWindow);
    WindowManager::setWindowMinSize(mainWindow, 960, 540);

    viewManager.setCanvas(windowInfo.width, windowInfo.height);
    viewManager.route(
        ViewManager::createView<TitleView>(renderer, viewManager));
}

Engine::~Engine()
{
    if (renderT.joinable())
        renderT.join();
    viewManager.quit();
    RendererManager::destroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    TY_CORE_INFO("Tysm closed");
}

void Engine::run()
{
    // 处理窗口resizing时保持渲染
    WindowEventData data = WindowEventData{renderer, &viewManager};
    SDL_AddEventWatch(WindowEventFilter, &data);
    while (!isQuit) {
        // Event
        while (SDL_PollEvent(&e)) {
            switch (e.type) {

                case SDL_QUIT:
                    isQuit = true;
                    break;
                    // 按下Alt Enter切换全屏
                case SDL_KEYDOWN:
                    if ((SDL_GetModState() & KMOD_ALT) &&
                        e.key.keysym.sym == SDLK_RETURN)
                        WindowManager::setWindowedOrFullDesktop(mainWindow);
                    break;
                default:
                    break;
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
    SDL_DelEventWatch(WindowEventFilter, &data);
}
} // namespace tysm
