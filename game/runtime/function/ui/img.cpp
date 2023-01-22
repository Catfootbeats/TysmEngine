#include "img.hpp"

namespace Tysm {
UI_Img::UI_Img(Position* position,
         const char* filePath,
         int width,
         int height,
         SDL_Renderer* renderer)
{
    background = new Tysm::Image(position, filePath,
                             width,height,renderer);
}

float UI_Img::calRatio()
{
    return background->calRatio();
}

void UI_Img::show()
{
    background->RenderImg();
}
}