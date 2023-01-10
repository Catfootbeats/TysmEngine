#pragma once

namespace Tysm {

struct Position {
    int x, y;
};

class Ty_Object {
public:
    virtual void show() = 0;
    Position m_position;
};
}  // namespace Tysm
