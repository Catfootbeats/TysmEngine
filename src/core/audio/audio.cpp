#include "log.hpp"

#include <SDL_mixer.h>
inline void audio(const char * path){
    Mix_Chunk* sound = Mix_LoadWAV(path);
    if (sound == nullptr) {
        TY_CORE_WARN(Mix_GetError());
        return;
    }
    if (Mix_PlayChannel(-1,sound,0) <0)
        TY_CORE_WARN(Mix_GetError());
}
