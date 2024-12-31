#include "ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>

namespace tysm {
TyObject::TyObject(SDL_Renderer *&renderer,
                   const char *name,
                   PositionScaler pos,
                   float size)
    : renderer(renderer), pos(pos), size(size), name(name)
{
}

TyObject::TyObject(SDL_Renderer *&renderer,
                   const char *name,
                   PositionScaler pos,
                   SizeScaler sizeScaler)
    : renderer(renderer), pos(pos), sizeScaler(sizeScaler), name(name)
{
}

TyObject::~TyObject()
{
    if (!dstRect)
        delete dstRect;
    SDL_DestroyTexture(texture);
}

void TyObject::render(CanvasData canvasData)
{
    if (!dstRect)
        delete dstRect;
    /*
    位置的计算：
    pos给的是宽度和高度的占比
    通过 占比*canvas高度宽度+偏移位置 计算出实际的位置

    大小的计算：
    size看作横向占比，去计算纵向距离, 1 并非实际大小，而是占满横向空间
    */
    if (size != 0) {
        dstRect = new SDL_Rect{
            static_cast<int>(canvasData.w * pos.xScaler + canvasData.xOffset),
            static_cast<int>(canvasData.h * pos.yScaler + canvasData.yOffset),
            static_cast<int>(canvasData.w * size),
            static_cast<int>((canvasData.w * size) / aspectRatio)};
        SDL_RenderCopy(renderer, texture, nullptr, dstRect);
        return;
    }
    /*
    直接指定长度和宽度的元素渲染
    */
    dstRect = new SDL_Rect{
        static_cast<int>(canvasData.w * pos.xScaler + canvasData.xOffset),
        static_cast<int>(canvasData.h * pos.yScaler + canvasData.yOffset),
        static_cast<int>(canvasData.w * sizeScaler.wScaler),
        static_cast<int>(canvasData.h * sizeScaler.hScaler)};
    SDL_RenderCopy(renderer, texture, nullptr, dstRect);
}
} // namespace tysm
