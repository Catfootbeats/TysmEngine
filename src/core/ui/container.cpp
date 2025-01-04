#include "container.hpp"

namespace tysm {
Container::Container(SDL_Renderer *&renderer,
                     const char *name,
                     Position pos,
                     Size size)
    : TyObject(renderer, name, pos, size)
{
}
} // namespace tysm
