#pragma once

#include "./../framework/object.hpp"
#include "./../render/image.hpp"

namespace Tysm {

class UI : public Ty_Object {
public:
    Position* m_pos{nullptr};
    int m_width = 0, m_height = 0;
    bool MouseOver();
    bool OnLeftClick();
    bool OnRightClick();

private:
};

}  // namespace Tysm
