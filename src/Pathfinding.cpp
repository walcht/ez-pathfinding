#include <iostream>

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

  /*
  std::stack< GridCaseNode* > DFS_stack;
  GeneralTree tree = GeneralTree();
  SA::DFS_iterative_elementary_init(MainGrid, tree, DFS_stack);
  */


  //std::queue< GridCaseNode* > BFS_queue;
  //GeneralTree tree = GeneralTree();
  //SA::BFS_iterative_elementary_init(MainGrid, tree, BFS_queue);

  SA::DFS DFS_algorithm(MainGrid);

  bool endCustomizationLoop = false;
  bool isLeftMouseButtonDown = false;
  bool isRightMouseButtonDown = false;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // INPUT LOOP
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  while (!quit && !endCustomizationLoop)
  {
    while (SDL_PollEvent(&e) != 0)    // handles user input
    {
      if (e.type == SDL_QUIT) quit = true;

      //User presses a key
      if ( e.type == SDL_KEYDOWN )
      {
        switch (e.key.keysym.sym) {
          case SDLK_EXECUTE:
          case SDLK_SPACE:
            endCustomizationLoop = true;
            break;
        }
      }

      if (e.type == SDL_MOUSEBUTTONDOWN)
        if (e.button.button == SDL_BUTTON_LEFT)
          isLeftMouseButtonDown = true;
        else if (e.button.button == SDL_BUTTON_RIGHT)
          isRightMouseButtonDown = true;

      if (e.type == SDL_MOUSEBUTTONUP)
        if (e.button.button == SDL_BUTTON_LEFT)
          isLeftMouseButtonDown = false;
        else if (e.button.button == SDL_BUTTON_RIGHT)
          isRightMouseButtonDown = false;
    }

    if (isLeftMouseButtonDown)    // add wall at where the mouse currently points
    {
        int x, y;
        Vector2D pos;

        SDL_GetMouseState(&y, &x);

        MainGrid.GetMouseGrid(pos, x, y);
        MainGrid.SetWallCase(pos);
    }

    if (isRightMouseButtonDown)   // remove wall at where the mouse currently points
    {
      int x, y;
      Vector2D pos;

      SDL_GetMouseState(&y, &x);

      MainGrid.GetMouseGrid(pos, x, y);
      MainGrid.ClearCase(pos);
    }

    MainRenderer.Clear(0x00, 0x00, 0x00);
    MainGrid.RenderGrid();

    MainRenderer.UpdateScreen();
  }

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

    if (DFS_algorithm.iterative_verify())
    {
      DFS_algorithm.iterative_elementary();
      MainGrid.DrawPath(DFS_algorithm.CurrentNode());
    }

    // draw start\end cases
    MainGrid.DrawStartCase();
    MainGrid.DrawEndCase();

    MainRenderer.UpdateScreen();
    SDL_Delay(10);
  }

  return 0;
}
