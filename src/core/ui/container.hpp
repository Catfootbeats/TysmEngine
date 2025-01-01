#pragma once

#include "ui/ty_object.hpp"
#include <vector>
namespace tysm {
// 用于列表，stack之类的有位置规则的容器
class Container : public TyObject {
public:
    Container(SDL_Renderer *&renderer,
              const char *name,
              PositionScaler pos,
              SizeScaler sizeScaler);

    // 继承Container要求重写render(CanvasData &canvasData)
    // render在渲染时通过改变输入的Canvas Data的值来渲染相应的对象

protected:
    CanvasData containerData;
    std::vector<TyObject *> children;
};
} // namespace tysm
