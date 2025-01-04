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
    const char *name{nullptr};
    Position pos = {500, 700};
    Size size = {500, 250};

    const char *text = nullptr;
    const char *fontPath = nullptr;
    int fontSize = 72;
    SDL_Color fontColor = {0, 0, 0, 255};

    const char *imgPath = nullptr;
    SDL_Color bgColor = {102, 204, 255, 255};

    SDL_Color borderColor = {255, 255, 255, 0};
    int borderWidth = 3;

    ButtonInfo &operator=(const ButtonInfo &info)
    {
        if (this == &info)
            return *this;
        renderer = info.renderer;
        name = info.name;
        pos = info.pos;
        size = info.size;
        text = info.text;
        fontPath = info.fontPath;
        imgPath = info.imgPath;
        bgColor = info.bgColor;
        borderColor = info.borderColor;
        borderWidth = info.borderWidth;
        return *this;
    }
};
class Button final : public TyObject {
public:
    explicit Button(ButtonInfo);

    void bindOnLeftClick(std::function<void()> func) override;
    void bindOnRightClick(std::function<void()> func) override;
    void bindOnFloat(std::function<void()> func) override;

    void update(SDL_Event &e, SDL_Rect &canvasRect) override;
    void draw(SDL_Texture *canvas) override;

    void setText(const char *text) override;
    void setFont(const char *fontPath) override;
    void setFontSize(int fontSize) override;
    void setImage(const char *path) override;
    void setBgColor(SDL_Color color) override;
    void setBorder(SDL_Color borderColor, int width) override;

private:
    std::unique_ptr<TTF_Font, FontDeleter> font_{nullptr};
    std::unique_ptr<SDL_Texture, TextureDeleter> bgTexture{nullptr};
    std::unique_ptr<SDL_Texture, TextureDeleter> textTexture{nullptr};

    ButtonInfo info_;
    ButtonInfo infoCopy_;
    bool isOnFloat = false;
    SDL_Rect textRect{};

    std::function<void()> onLeftClickFunc;
    std::function<void()> onRightClickFunc;
    std::function<void()> onFloatFunc; // 仅为进入操作, 推出之后会恢复
    void checkIsFloat(const SDL_Event &e, const SDL_Rect &canvasRect);
    void checkIsClick(const SDL_Event &e) const;
    void createTextTexture(const ButtonInfo &info);
    void createImageTexture(const ButtonInfo &info);
};
} // namespace tysm
