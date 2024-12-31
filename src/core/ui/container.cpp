#include "container.hpp"

namespace tysm {
Container::Container(SDL_Renderer *&renderer,
                     const char *name,
                     PositionScaler pos,
                     SizeScaler sizeScaler)
    : TyObject(renderer, name, pos, sizeScaler)
{
}
} // namespace tysm
