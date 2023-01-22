#pragma once

#include "./../render/image.hpp"
#include "./../render/text.hpp"
#include "ui.hpp"

// std
#include <string>
namespace Tysm {
class UI_Button : public UI {
public:
    UI_Button(Position* pos,
              int width,
              int height,
              const char* background,
              const char* fontPath,
              std::string str,
              SDL_Renderer* renderer);
    void show();

    ~UI_Button();

private:
    Tysm::Image* background{nullptr};
    Tysm::Text* text{nullptr};
};
}  // namespace Tysm
