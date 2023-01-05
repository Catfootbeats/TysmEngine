#include "window_system.hpp"

namespace Tysm {
WindowSystem::~WindowSystem()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
} //namespace Tysm