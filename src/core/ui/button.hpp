#pragma once

#include "ui/ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_pixels.h>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <functional>
namespace tysm {

struct ButtonInfo {
    SDL_Renderer *&renderer;
    const char *name;
    Position pos = {0, 0};
    Size size = {50, 25};
    const char *text = nullptr;
    TTF_Font *font = nullptr;
    SDL_Color fontColor = {0, 0, 0, 255};
    const char *imgPath = nullptr;
    SDL_Color bgColor = {255, 255, 255, 0};
    SDL_Color borderColor = {255, 255, 255, 0};
};
class Button : public TyObject {
public:
    Button(ButtonInfo);
    ~Button() = default;

    const char *text;
    const char *imgPath;
    SDL_Color fontColor;
    SDL_Color bgColor;
    SDL_Color borderColor;

    void bindOnClick(std::function<void()> func) override;
    void bindOnFloat(std::function<void()> func) override;

    void update(SDL_Event &e, SDL_Rect &canvasData) override;

private:
    int x, y, w, h;
    TTF_Font *font;
    SDL_Texture *bgTexture{nullptr};
    SDL_Texture *textTexture{nullptr};

    std::function<void()> onClickFunc;
    std::function<void()> onFloatFunc;
    bool isFloat(SDL_Event &e, SDL_Rect &canvasData);
    bool isClick(SDL_Event &e, SDL_Rect &canvasData);
    // 不支持重新设置字体
    void initTextTexture();
    void initImgTexture();
};
} // namespace tysm
