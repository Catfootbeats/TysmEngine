#pragma once

namespace tysm{
class IView {
public:
    virtual ~IView() = default;
    virtual void show() = 0;
    virtual void update(SDL_Event&) = 0;
};
}