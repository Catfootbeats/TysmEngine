#pragma once

#include "utils/vec2.hpp"
#include <SDL_events.h>
#include <SDL_render.h>
#include <functional>

namespace tysm {
class TyObject {
public:
    //有固定宽高比的元素 图片文字
    explicit TyObject(SDL_Renderer *&renderer,
                      const char *name,
                      Position pos,
                      float scale = 1.0);
    //有固定长宽的元素 按钮 列表
    explicit TyObject(SDL_Renderer *&renderer,
                      const char *name,
                      Position pos,
                      Size size);
    virtual ~TyObject();
    virtual void update(SDL_Event &e, SDL_Rect &canvasData,SDL_Window*&window) {}
    virtual void draw(SDL_Texture *canvas);

    // 只有特定重写了的组件才能触发
    // 绑定左键点击事件 触发一次
    virtual void bindOnLeftClick(std::function<void()> func) {}
    // 绑定右键点击事件 触发一次
    virtual void bindOnRightClick(std::function<void()> func) {}
    virtual void bindOnFloat(std::function<void()> func) {}
    virtual void setText(const char *text) {}
    virtual void setFont(const char *fontPath) {}
    virtual void setFontSize(int fontSize) {}
    virtual void setImage(const char *path) {}
    virtual void setBgColor(SDL_Color color){}
    virtual void setBorder(SDL_Color borderColor,int width){}

    const char *name;
    Position pos{0, 0};
    Size size{0, 0};
    float scale{1.0};

protected:
    SDL_Renderer *&renderer;
    SDL_Rect *dstRect{nullptr};
    SDL_Texture *texture{nullptr};
};
} // namespace tysm
