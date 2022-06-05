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


  std::stack< GridCaseNode* > DFS_stack;
  GeneralTree tree = GeneralTree();
  SA::DFS_iterative_elementary_init(MainGrid, tree, DFS_stack);


  /*
  std::queue< GridCaseNode* > BFS_queue;
  GeneralTree tree = GeneralTree();
  SA::BFS_iterative_elementary_init(MainGrid, tree, BFS_queue);
  */

  bool endInputLoop = false;
  bool isMouseDown = false;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // INPUT LOOP
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  while (!quit && !endInputLoop)
  {
    while (SDL_PollEvent(&e) != 0)    // handles user input
    {
      if (e.type == SDL_QUIT) quit = true;

      //User presses a key
      else if ( e.type == SDL_KEYDOWN )
      {
        switch (e.key.keysym.sym) {
          case SDLK_SPACE: endInputLoop = true;
        }
      }

      else if (e.type == SDL_MOUSEBUTTONDOWN)
      {
        isMouseDown = true;
        int x, y;
        Vector2D pos;

        SDL_GetMouseState(&y, &x);

        MainGrid.GetMouseGrid(pos, x, y);
        MainGrid.SetWallCase(pos);
      }

      else if (e.type == SDL_MOUSEBUTTONUP)
      {
        isMouseDown = false;
      }

    }

    if (isMouseDown)
    {

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


    if (SA::DFS_iterative_elementary_verify(MainGrid, tree, DFS_stack))
    {
      SA::DFS_iterative_elementary(MainGrid, tree, DFS_stack);
      SA::Draw_path(MainGrid, DFS_stack.top());
    }

    /*
    if (SA::BFS_iterative_elementary_verify(MainGrid, tree, BFS_queue))
    {
      SA::BFS_iterative_elementary(MainGrid, tree, BFS_queue);
      SA::Draw_path(MainGrid, BFS_queue.front());
    }
    */

    // draw start\end cases
    MainGrid.DrawStartCase();
    MainGrid.DrawEndCase();

    MainRenderer.UpdateScreen();
    SDL_Delay(200);
  }

  return 0;
}
