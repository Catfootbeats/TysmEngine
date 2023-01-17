#include "game.hpp"

namespace Tysm {
Game::Game()
{
    engine = new Tysm::Engine;
    windowSystem = new Tysm::WindowSystem;
}

Game::~Game()
{
    delete engine;
    delete windowSystem;
    delete renderSystem;
}

void Game::init()
{
    engine->TyInitEngine();
    TyWindowCreateInfo createInfo;
    createInfo.title = "hello tysm game";
    createInfo.is_fullscreen = false;
    windowSystem->init(createInfo);
    window = windowSystem->getWindow();
    renderSystem = new Tysm::RenderSystem(window);
    windowSystem->setIcon("resources/tysm_icon.bmp");
    start();
}

void Game::start()
{
    gameState = Tysm::GameState::Gaming;
}

void Game::run()
{
    engine->run();
    //main game while
    while (!isQuit) {
        while (windowSystem->pollEvents()) {
            if (windowSystem->getEvent().type == SDL_QUIT) isQuit = true;
        }
        switch (gameState) {
            case StartMenu:
                startRender();
            case Gaming:
                gamingRender();
        }
        renderSystem->clear();
        // TY_INFO("Game is running!");
    }
}

void Game::startRender()
{
    static RenderInfo* startSceneRenderInfo{nullptr};
    renderSystem->present(startSceneRenderInfo);
}

void Game::gamingRender()
{
    static RenderInfo* gamingSceneRenderInfo{nullptr};
    renderSystem->present(gamingSceneRenderInfo);
}
}  // namespace Tysm
