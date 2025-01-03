#include <SDL_rect.h>
#include "config.hpp"
namespace tysm{
void toActualRect(SDL_Rect &dstRect, const SDL_Rect &canvasRect)
{
    const float k = static_cast<float>(canvasRect.w) / CANVAS_WIDTH;
    dstRect.w = dstRect.w * k;
    dstRect.h = dstRect.h * k;
    dstRect.x = dstRect.x * k + canvasRect.x;
    dstRect.y = dstRect.y * k + canvasRect.y;
}
}