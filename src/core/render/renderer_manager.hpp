#pragma once

#include <SDL_render.h>
namespace tysm {
class RendererManager {
public:
    static void initRenderer(SDL_Renderer *&renderer, SDL_Window *&window);
    static void destroyRenderer(SDL_Renderer *&renderer);

private:
    RendererManager() = default;
};
} // namespace tysm
