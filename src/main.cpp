#include <SDL.h>
#include <cstdio>

#include "log/log.hpp"

int main(int argc, char *argv[])
{
    //初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("can not init SDL:%s", SDL_GetError());
        return -1;
    }
    tysm::Log::Init();
    TY_CORE_INFO("SUCCESS!!!")
    std::getchar();

    return 0;
}
