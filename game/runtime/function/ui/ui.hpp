#pragma once

#include "./../framework/object.hpp"
#include "./../render/image.hpp"

namespace Tysm {

class UI : public Ty_Object {
public:
    int width, height;
    bool MouseOver();
    bool OnClick();
private:
};

}  // namespace Tysm
