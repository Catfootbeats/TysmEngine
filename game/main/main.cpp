#include <iostream>

#include "game.hpp"

int main(int args, char* argv[])
{
    Tysm::Game* game = new Tysm::Game;

    game->init();
    game->run();
    delete game;
    return 0;
}
