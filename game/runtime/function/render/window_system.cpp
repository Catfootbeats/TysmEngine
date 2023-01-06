#include "window_system.hpp"

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
    }else {
        flags = SDL_WINDOW_SHOWN;
    }
    m_window = SDL_CreateWindow(createInfo.title, SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, createInfo.width,
                                createInfo.height,
                                flags);
    SDL_Renderer *renderer = SDL_CreateRenderer(m_window, -1, 0);

    int w, h;

    bool isQuit = false;
    SDL_Event event;

    Tysm::Log::Init();
    Tysm::Log::GetCoreLogger()->info("LogSystem load!");

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    while (!isQuit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isQuit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_Rect dstrect;
        dstrect.x = 100;
        dstrect.y = 100;
        dstrect.w = w;
        dstrect.h = h;

        SDL_RenderPresent(renderer);
    }
}
} //namespace Tysm
