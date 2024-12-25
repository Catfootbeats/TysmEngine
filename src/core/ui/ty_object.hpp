#pragma once

#include <SDL_render.h>

namespace tysm{
class TyObject
{
public:
  void render();
  private:
  SDL_Renderer*& renderer;
  SDL_Texture* texture;
  SDL_Rect* srcRect{nullptr};
  SDL_Rect* dstRect{nullptr};

};
} // namespace tysm
