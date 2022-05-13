#include "Renderer.hpp"
#include "Grid.hpp"
#include "SearchAlgorithms.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int main(int argc, char const* argv[]) {

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Instantiation
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Renderer MainRenderer = Renderer(682, 682);     // main renderer that handles rendering functionalities
  Grid MainGrid = Grid(MainRenderer, 40, 40);     // the grid contating all information related to grid
  bool quit = false;                              // for knowing when to quit application
  SDL_Event e;                                    // for catching SDL events


  MainGrid.SetStartCase(GridCase(0, 0, false));
  MainGrid.SetEndCase(GridCase(39, 39, false));


  SA::DFS_iterative_dirty(MainGrid, MainRenderer, 200);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Game Loop
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  while (!quit) {

    while (SDL_PollEvent(&e) != 0)    // handles user input
    {
      if (e.type == SDL_QUIT) quit = true;
    }
    MainRenderer.Clear(0x00, 0x00, 0x00);

    // draw everything here
    MainGrid.RenderGrid();
    MainGrid.RenderGridCase(0, 5, 0x00, 0x00, 0x00);

    // draw start\end cases
    MainGrid.DrawStartCase();
    MainGrid.DrawEndCase();

    MainRenderer.UpdateScreen();
  }

  return 0;
}
