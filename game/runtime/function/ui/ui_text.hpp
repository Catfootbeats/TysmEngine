#pragma once

#include "./../render/text.hpp"
#include "ui.hpp"
namespace Tysm {

class UI_Text : public UI {
public:
    UI_Text(Position* pos,
            const char* fontPath,
            int fontSize,
            std::string str,
            SDL_Color fg,
            SDL_Renderer* renderer);
    void show();
    ~UI_Text();

private:
    Tysm::Text* text{nullptr};
    SDL_Color fgColor = {255,255,255,255};
    std::string m_str = "text";
};
}  // namespace Tysm
