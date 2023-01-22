#include "game.hpp"

#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_scancode.h>
#include <SDL_timer.h>
#include <SDL_video.h>

namespace Tysm_Game {
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
    Tysm::TyWindowCreateInfo createInfo;
    createInfo.title = "hello tysm game";
    createInfo.is_fullscreen = false;
    createInfo.width = 1600;
    createInfo.height = 900;
    createInfo.can_Resize = false;
    windowSystem->init(createInfo);
    window = windowSystem->getWindow();
    renderSystem = new Tysm::RenderSystem(window);
    windowSystem->setIcon("resources/tysm_icon.bmp");
    // start();
}

void Game::start()
{
    gameState = Tysm_Game::GameState::Gaming;
}

void Game::run()
{
    engine->run();
    switch (gameState) {
        case StartMenu:
            startSceneStart();
        case Gaming:
            gamingSceneStart();
    }
    //main game while
    while (!isQuit) {
        while (windowSystem->pollEvents()) {
            if (windowSystem->getEvent().type == SDL_QUIT) isQuit = true;
            // if (windowSystem->getEvent().type == SDL_KEYDOWN) {
            //     if (windowSystem->getEvent().key.keysym.scancode ==
            //             SDL_SCANCODE_COMMA &&
            //         windowSystem->getEvent().key.keysym.mod & KMOD_ALT &&
            //         windowSystem->getEvent().key.keysym.mod & KMOD_RESERVED) {
            //     }
            // }
        }

        renderSystem->clear();
        switch (gameState) {
            case StartMenu:
                if (startScene->reCreateScene(
                        windowSystem->getWindowSize()[0],
                        windowSystem->getWindowSize()[1])) {
                }
                startScene->run();
                break;
            case Gaming:
                break;
        }
        renderSystem->present();
        SDL_Delay(1000 / 60);
        // TY_INFO("Game is running!");
    }
}

void Game::altEnterFullSrc()
{
}

void Game::startSceneStart()
{
    startScene = new Tysm_Game::StartScene(renderSystem,
                                           windowSystem->getWindowSize()[0],
                                           windowSystem->getWindowSize()[1]);
    startScene->start();
}

void Game::gamingSceneStart()
{
    // TODO move to gaming Scene
    //renderSystem->present();
}

void Game::logicUpdate() {}
}  // namespace Tysm_Game
