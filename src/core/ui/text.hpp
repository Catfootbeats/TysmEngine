#pragma once

#include "ui/ty_object.hpp"
#include "utils/vec2.hpp"
#include <SDL_ttf.h>

namespace tysm {
struct TextInfo {
    SDL_Renderer *&renderer;
    const char *name{};
    const char *fontPath{};
    int fontSize = 144;
    const char *text{"我是一行文字哼哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊"};
    SDL_Color color = {0, 0, 0};
    Position pos = {0, 0};
};
class Text final : public TyObject {
public:
    explicit Text(const TextInfo &);

    void setText(const char *text) override;
    void setFont(const char *fontPath) override;
    void setFontSize(int fontSize) override;

private:
    TTF_Font *font_{nullptr};
    TextInfo info_;

    void createTexture(const TextInfo &info);
};
} // namespace tysm
