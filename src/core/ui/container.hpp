#pragma once

#include "ui/ty_object.hpp"
#include <vector>
namespace tysm {
class Container : public TyObject {
public:
    Container(SDL_Renderer *&renderer,
              const char *name,
              PositionScaler pos,
              SizeScaler sizeScaler);

    // 继承Container要求重写render(CanvasData &canvasData)

protected:
    CanvasData containerData;
    std::vector<TyObject *> children;
};
} // namespace tysm
