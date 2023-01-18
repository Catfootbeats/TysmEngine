#include <iostream>

#include "game.hpp"


int main(int args, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        TY_CORE_ERROR("sdl init failed");
    }
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    
    Tysm_Game::Game* game = new Tysm_Game::Game;

    game->init();
    game->run();
    delete game;

    IMG_Quit();
    SDL_Quit();

    return 0;
}
