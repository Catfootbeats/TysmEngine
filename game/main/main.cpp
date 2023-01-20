#include <iostream>

#include "game.hpp"

int main(int args, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        TY_CORE_ERROR("sdl init failed");
    }
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    // anti-aliasing
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "best");

    // https://www.bilibili.com/festival/VSF2023live?bvid=BV1rY4y1Z7Rj
    // 真的超级好听，如果你看到这行注释一定要汀汀！ヾ(≧▽≦*)o

    Tysm_Game::Game* game = new Tysm_Game::Game;

    game->init();
    game->run();
    delete game;

    IMG_Quit();
    SDL_Quit();

    return 0;
}
