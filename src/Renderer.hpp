#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <cassert>

// this class wraps the window and the renderer in the same entity
class Renderer {
private:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  int _window_width;           // window is assumed to be squared, thus width and height are the same
  int _window_height;

public:
  Renderer(int window_width, int window_height);
  ~Renderer();

  void RenderRectangle(const SDL_Rect& fill_rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a) const;

  int GetWidth() const;
  int GetHeight() const;

  void UpdateScreen();
  void Clear(Uint8 r, Uint8 g, Uint8 b);
};

#endif
