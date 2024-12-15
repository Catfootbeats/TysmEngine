#pragma once

namespace tysm {
class IView {
public:
    virtual void show() = 0;
    IView() = default;
};
} // namespace tysm
