#include "event_manager.hpp"

namespace tysm {
void EventManager::pollEvent(SDL_Event &event, bool &isQuit)
{
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isQuit = true;
        }
    }
}
} // namespace tysm
