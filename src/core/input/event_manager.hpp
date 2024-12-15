#pragma once

#include <SDL_events.h>
namespace tysm {
class EventManager {
public:
    static void pollEvent(SDL_Event &event, bool &isQuit);

private:
    EventManager() = default;
    ~EventManager();
};
} // namespace tysm
