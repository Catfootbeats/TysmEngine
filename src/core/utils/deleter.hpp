#pragma once
#include <SDL_mixer.h>
#include <SDL_render.h>
#include <SDL_ttf.h>

struct RendererDeleter {
    void operator()(SDL_Renderer* ptr) const {
        SDL_DestroyRenderer(ptr);
    }
};

struct WindowDeleter {
    void operator()(SDL_Window* ptr) const {
        SDL_DestroyWindow(ptr);
    }
};

struct FontDeleter {
    void operator()(TTF_Font* ptr) const {
        TTF_CloseFont(ptr);
    }
};

struct TextureDeleter {
    void operator()(SDL_Texture* ptr) const {
        SDL_DestroyTexture(ptr);
    }
};

struct MusicDeleter {
    void operator()(Mix_Music* ptr) const {
        Mix_FreeMusic(ptr);
    }
};