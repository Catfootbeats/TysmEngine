#include "img.hpp"

namespace Tysm {
Img::Img(Position* position,
         const char* filePath,
         int width,
         int height,
         SDL_Renderer* renderer)
{
    background = new Tysm::Image(position, filePath,
                             width,height,renderer);
}

float Img::calRatio()
{
    return background->calRatio();
}

void Img::show()
{
    background->RenderImg();
}
}