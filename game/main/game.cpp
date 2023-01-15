#include "game.hpp"

namespace Tysm {
Game::Game()
{
    engine = new Tysm::Engine;
    windowSystem = new Tysm::WindowSystem;
    renderSystem = new Tysm::RenderSystem(windowSystem->getWindow());
}

Game::~Game()
{
    delete engine;
    delete windowSystem;
    delete renderSystem;
}

void Game::start()
{
    engine->TyInitEngine();
    TyWindowCreateInfo createInfo;
    createInfo.title = "hello tysm game";
    createInfo.is_fullscreen = false;
    windowSystem->init(createInfo);
    windowSystem->setIcon("resources/tysm_icon.bmp");
}

void Game::run()
{
    engine->run();
    //main game while
    while (!isQuit) {
        while (windowSystem->pollEvents()) {
            if (windowSystem->getEvent().type == SDL_QUIT)
                isQuit = true;
        }
        //TY_INFO("Game is running!");
    }
}
}  // namespace Tysm
