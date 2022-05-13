#include <iostream>
#include <cassert>

#include "Renderer.hpp"


Renderer::Renderer(int window_width, int window_height) : _window_width{window_width}, _window_height{window_height}
{
  _window = SDL_CreateWindow(   "Rendering Textures", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                window_width, window_height, SDL_WINDOW_SHOWN
                            );
  assert(_window != NULL);

  _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
  assert(_renderer != NULL);
}

Renderer::~Renderer()
{
    // freeing allocated renderer and window memory
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);

    // Quiting SDL subsystems
    //IMG_Quit();
    SDL_Quit();
}

void Renderer::RenderRectangle(const SDL_Rect& fill_rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a) const
{
  SDL_SetRenderDrawColor(_renderer, r, g, b, a);
  SDL_RenderFillRect(_renderer, &fill_rect);
}

int Renderer::GetWidth () const
{
  return _window_width;
}

int Renderer::GetHeight() const
{
  return _window_height;
}

void Renderer::Clear(Uint8 r, Uint8 g, Uint8 b)
{
  SDL_SetRenderDrawColor(_renderer, r, g, b, 0xFF);
  SDL_RenderClear(_renderer);
}

void Renderer::UpdateScreen()
{
  SDL_RenderPresent(_renderer);
}
