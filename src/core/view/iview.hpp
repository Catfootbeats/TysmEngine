#pragma once

#include "utils/canvas_data.hpp"
#include <SDL_events.h>
namespace tysm {
class IView {
public:
    virtual ~IView() = default;
    virtual void show(CanvasData &) = 0;
    virtual void update(SDL_Event &, CanvasData &) = 0;
};
} // namespace tysm
