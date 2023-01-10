#include "render_system.hpp"

#include <SDL_render.h>

namespace Tysm {
RenderSystem::RenderSystem(SDL_Window* window)
{
    m_render = SDL_CreateRenderer(window, -1, 0);
}

RenderSystem::~RenderSystem()
{
    SDL_DestroyRenderer(m_render);
}

void RenderSystem::init() {}

SDL_Renderer* RenderSystem::getRenderer()
{
    return m_render;
}

}  // namespace Tysm
