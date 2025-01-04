#include "renderer_manager.hpp"
#include "log.hpp"

#include <SDL_hints.h>

namespace tysm {
void RendererManager::initRenderer(SDL_Renderer *&renderer, SDL_Window *&window)
{
    renderer = SDL_CreateRenderer(window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        TY_CORE_ERROR(SDL_GetError());
        return;
    }
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        TY_CORE_WARN("Linear texture filtering not enabled!");
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
}
} // namespace tysm
