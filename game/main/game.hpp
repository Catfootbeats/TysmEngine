#pragma once

#include "engine.hpp"
#include "function/render/render_system.hpp"

namespace Tysm {
class Game {
public:
    Game();
    ~Game();
    void start();
    void run();

private:
    Tysm::Engine* engine{nullptr};
    Tysm::WindowSystem* windowSystem{nullptr};
    Tysm::RenderSystem* renderSystem{nullptr};
    bool isQuit{false};
};

}  // namespace Tysm
