

#include <SDL_render.h>

void textureDeleter(SDL_Texture* ptr)
{
    SDL_DestroyTexture(ptr);
}