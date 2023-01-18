#pragma once

//std
#include <string>

namespace Tysm {

struct Position {
    int x, y;
};

class Ty_Object {
public:
    virtual void show() = 0;
    Position position;
    std::string name;

    Ty_Object() = default;
};
}  // namespace Tysm
