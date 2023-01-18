#pragma once

#include "engine.hpp"
#include "start_scene.hpp"
#include "function/render/render_system.hpp"

namespace Tysm_Game {
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
    Tysm_Game::GameState gameState = Tysm_Game::GameState::StartMenu;
    Tysm_Game::StartScene* startScene{nullptr};
    // TODO gamingScene
    bool isQuit{false};

    void start();
    void logicUpdate();
    void startSceneStart();
    void gamingSceneStart();
};

}  // namespace Tysm
