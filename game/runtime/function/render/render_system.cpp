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

void RenderSystem::draw(std::vector<Ty_Object*>* objs)
{
    if (objs != nullptr) {
        for (Ty_Object* i : *objs) {
            i->show();
        }
    }else {
        TY_CORE_WARN("RenderInfo is a nullptr");
    }

}

void RenderSystem::clear()
{
    SDL_SetRenderDrawColor(m_render, 0, 0, 0, 255);
    SDL_RenderClear(m_render);
}

void RenderSystem::present()
{
    SDL_RenderPresent(m_render);
}

void RenderSystem::renderImg(const char* ImgPath)
{

}
}  // namespace Tysm
