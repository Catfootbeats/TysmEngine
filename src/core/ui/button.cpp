#include "ui/button.hpp"
#include "ui/ty_object.hpp"

namespace tysm {
Button::Button(ButtonInfo info)
    : TyObject(info.renderer, info.name, info.pos, info.size)
{
}
} // namespace tysm
