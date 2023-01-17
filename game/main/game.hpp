#pragma once

#include "engine.hpp"
#include "function/render/render_system.hpp"

namespace Tysm {
enum GameState{
    StartMenu,
    Gaming
};
class Game {
public:
    Game();
    ~Game();
    // init window and game
    void init();
    // start game, change state to gaming
    void run();

private:
    Tysm::Engine* engine{nullptr};
    SDL_Window* window{nullptr};
    Tysm::WindowSystem* windowSystem{nullptr};
    Tysm::RenderSystem* renderSystem{nullptr};
    Tysm::GameState gameState = Tysm::GameState::StartMenu;
    bool isQuit{false};

    void start();
    void startRender();
    void gamingRender();
};

}  // namespace Tysm
