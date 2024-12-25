#pragma once

#include <SDL_render.h>
#include "ty_object.hpp"

namespace tysm{
class Image:public TyObject {
    public:
Image(SDL_Renderer*& renderer,const char* path);
~Image();
private:
};
}

