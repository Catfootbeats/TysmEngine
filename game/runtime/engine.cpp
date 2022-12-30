#include "engine.hpp"
#include <SDL_video.h>

#include "core/log/log_system.hpp"
#define WindowWidth 800
#define WindowHeight 600
int initWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        SDL_Log("sdl init failed!");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Tysm Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WindowWidth, WindowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

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

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    /*
     * 1. Renderer <- Create <- SDL_SetRenderDrawColor <- SDL_RenderClear <- SDL_RenderDrawXXX Line Rect Pixel <- SDL_RenderCop[Ex] <- SDL_RenderPresent
     * 2. Texture <- SDL_CreateTextureFromSurface <- SDL_CreateTexture SDL_UpdateTexture <- SDL_QueryTexture <- SDL_SetTextureBlendMod <- SDL_SetTextureDrawColor
     * 3. Surface <- SDL_CreateRGBSurfaceWithFormat <- Point - Surface
     * 4. SDL_image
     */

    SDL_Quit();
    return 0;
}
