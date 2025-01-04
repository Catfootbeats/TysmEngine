#pragma once

#include <SDL_render.h>
namespace tysm {
class RendererManager {
public:
    static void initRenderer(SDL_Renderer *&renderer, SDL_Window *&window);
private:
    RendererManager() = default;
};
} // namespace tysm
