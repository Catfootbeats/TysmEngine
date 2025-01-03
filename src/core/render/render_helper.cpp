

#include <SDL_render.h>
namespace tysm::render {
void DrawRectWidth(SDL_Renderer* renderer,SDL_Rect* _rect,int width)
{
    SDL_Rect rect = *_rect;
    SDL_RenderDrawRect(renderer,&rect);
    for (int i = 1; i < width; ++i) {
        rect.x += 1;
        rect.y += 1;
        rect.w -= 2;
        rect.h -= 2;
        SDL_RenderDrawRect(renderer,&rect);
    }
}
}