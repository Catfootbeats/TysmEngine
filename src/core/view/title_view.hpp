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

private:
    TTF_Font *titleFont;
    Image background;
    //Text title;
};

} // namespace tysm
