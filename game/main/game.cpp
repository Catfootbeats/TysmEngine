#include "game.hpp"

namespace Tysm {
    Game::Game(){
        engine = new Tysm::Engine;
    }

    Game::~Game(){
        delete engine;
    }

    void Game::start(){
        engine->TyInitEngine();
    }

    void Game::run() {
        engine->run();

        //main game while 
        while (1) {
            TY_INFO("Game is running!");
        }
    }
} // namespace Tysm