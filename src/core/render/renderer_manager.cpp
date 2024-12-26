#include "renderer_manager.hpp"
#include "log.hpp"

namespace tysm {
void RendererManager::initRenderer(SDL_Renderer *&renderer, SDL_Window *&window)
{
    renderer = SDL_CreateRenderer(window, 1, 0);
    if (!renderer) {
        TY_CORE_ERROR(SDL_GetError());
    }
}
void RendererManager::destroyRenderer(SDL_Renderer *&renderer){
    SDL_DestroyRenderer(renderer);
    }
} // namespace tysm
