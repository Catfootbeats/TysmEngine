#pragma once

#include <SDL_events.h>
namespace tysm {
class IView {
public:
    virtual ~IView() = default;
    virtual void draw(SDL_Texture* ) = 0;
    virtual void update(SDL_Event &, SDL_Rect &) = 0;
};
} // namespace tysm
