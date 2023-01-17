#pragma once

#include "object.hpp"

//std
#include <vector>

namespace Tysm {
class Scene {
public:
    virtual std::vector<Ty_Object*> getObject() = 0;

private:
    
};
}  // namespace Tysm
