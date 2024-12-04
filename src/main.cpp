#include <SDL.h>
#include <cstdio>
#include <fmt/color.h>
#include <fmt/core.h>

int main(int argc, char *argv[])
{
    //初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("can not init SDL:%s", SDL_GetError());
        return -1;
    }
    fmt::print("成功!");
    std::getchar();

    return 0;
}
