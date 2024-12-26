#pragma once
#include "ui/image.hpp"
#include "ui/text.hpp"
#include "view_base.hpp"

#include <SDL2/SDL_ttf.h>
#include <SDL_render.h>
namespace tysm {

class TitleView : public ViewBase {
public:
    explicit TitleView(SDL_Renderer *&renderer);
    ~TitleView();

private:
    TTF_Font* titleFont;
};

} // namespace tysm
