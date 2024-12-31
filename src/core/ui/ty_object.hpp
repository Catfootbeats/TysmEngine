#pragma once

#include "utils/canvas_data.hpp"
#include "utils/vec2.hpp"
#include <SDL_render.h>

namespace tysm {
class TyObject {
public:
    //有固定宽高比的元素
    explicit TyObject(SDL_Renderer *&renderer,
                      const char *name,
                      PositionScaler pos,
                      float size);
    //有固定长宽的元素
    explicit TyObject(SDL_Renderer *&renderer,
                      const char *name,
                      PositionScaler pos,
                      SizeScaler sizeScaler);
    ~TyObject();
    void render(CanvasData canvasData);
    const char *name;

private:
    SDL_Renderer *&renderer;

protected:
    // UI组件必须赋值 w/h
    float aspectRatio;
    PositionScaler pos{0, 0};
    SizeScaler sizeScaler{0, 0};
    float size{0};
    SDL_Rect *dstRect{nullptr};
    SDL_Texture *texture{nullptr};
};
} // namespace tysm
