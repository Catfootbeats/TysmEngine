#pragma once

#include "utils/canvas_data.hpp"
#include "utils/vec2.hpp"
#include <SDL_render.h>

namespace tysm {
class TyObject {
public:
    explicit TyObject(SDL_Renderer *&renderer, Position pos, float size);
    ~TyObject();
    void render(CanvasData canvasData);

private:
    SDL_Renderer *&renderer;

protected:
    // UI组件必须赋值 w/h
    float aspectRatio;

    Position pos;
    float size;
    SDL_Rect *dstRect{nullptr};
    SDL_Texture *texture{nullptr};
};
} // namespace tysm
