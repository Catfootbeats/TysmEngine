#pragma once

#include "./../framework/object.hpp"
#include "./../render/image.hpp"

namespace Tysm {

class UI : public Ty_Object {
public:
    Position m_pos;
    int m_width, m_height;
    bool MouseOver();
    bool OnLeftClick();
    bool OnRightClick();

private:
};

}  // namespace Tysm
