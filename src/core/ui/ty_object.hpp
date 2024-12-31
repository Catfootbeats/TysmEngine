#pragma once

#include "utils/canvas_data.hpp"
#include "utils/vec2.hpp"
#include <SDL_events.h>
#include <SDL_render.h>
#include <functional>

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
    virtual void update(SDL_Event &e, CanvasData &canvasData) {}
    virtual void render(CanvasData &canvasData);
    virtual void bindOnClick(std::function<void()> func) {}
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
