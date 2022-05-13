#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include "Common.hpp"
#include "Grid.hpp"
#include "Tree.hpp"

#include <stack>
#include <queue>

namespace SA {

  void Draw_path(Grid& grid, GridCaseNode* node);


  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // DEPTH FIRST SEARCH ALGORITHMS: DFS, DLS
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void DFS_iterative(const Grid& grid);                               // vanilla search algorithm: usefull for a more accurate estimation
                                                                      // of the algorithms performance.

  void DFS_iterative_dirty( Grid&       grid,                   // dirty search algorithm: estimation of algorithms performance
                            Renderer&   renderer,               // using this function is NOT accurate due to calls to graphics
                            int               delayTime               // API, Timers, etc...
                          );

  void DFS_iterative_elementary(Grid& grid, GeneralTree& tree, std::stack< GridCaseNode* >& DFS_stack);
  //void DLS_iterative(const Grid& grid, int depth_limit);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // A* ALGORITHMS
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





} /* SA */


void SA::DFS_iterative(const Grid& grid)
{
  std::stack< GridCaseNode* > DFS_stack;

  GeneralTree tree = GeneralTree();     // usefull for determining discovered cases (discovered = a case that the algorithm walked through before)
                                        // according to the chosen data structure, there is a trade-off between space and time complexity

  GridCaseNode* current_node = tree.CreateNewNode(grid.GetStartCase().position, NULL);

  DFS_stack.push(current_node);

  while (!DFS_stack.empty())
  {
    current_node = DFS_stack.top();
    DFS_stack.pop();
    if (current_node->position == grid.GetEndCase().position)             // we have reached the first path to the objective!
    {                                                                     // not necessarilly the shortest
      printf("YO WE GOT THIS!");
      return;
    }

    if (!current_node->isDiscovered)
    {
      current_node->isDiscovered = true;

      //it is waaaay much better to change this whole section a For each loop
      if (grid.IsCaseAccessible(current_node->position.x - 1, current_node->position.y))
      {

        current_node->case_up_node = tree.CreateNewNode(current_node->position.x - 1, current_node->position.y, current_node);
        DFS_stack.push(current_node->case_up_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x, current_node->position.y - 1))
      {
        current_node->case_left_node = tree.CreateNewNode(current_node->position.x, current_node->position.y - 1, current_node);
        DFS_stack.push(current_node->case_left_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x + 1, current_node->position.y))
      {
        current_node->case_down_node = tree.CreateNewNode(current_node->position.x + 1, current_node->position.y, current_node);
        DFS_stack.push(current_node->case_down_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x, current_node->position.y + 1))
      {
        current_node->case_right_node = tree.CreateNewNode(current_node->position.x, current_node->position.y + 1, current_node);
        DFS_stack.push(current_node->case_right_node);
      }
      printf("how many times?\n");
    }

  }

} /* DFS_iterati */






void SA::DFS_iterative_dirty(Grid& grid, Renderer& renderer, int delayStepTime)
{
  std::stack< GridCaseNode* > DFS_stack;

  GeneralTree tree = GeneralTree();     // usefull for determining discovered cases (discovered = a case that the algorithm walked through before)
                                        // according to the chosen data structure, there is a trade-off between space and time complexity

  GridCaseNode* current_node = tree.CreateNewNode(grid.GetStartCase().position, NULL);

  DFS_stack.push(current_node);

  while (!DFS_stack.empty())
  {
    current_node = DFS_stack.top();
    DFS_stack.pop();
    if (current_node->position == grid.GetEndCase().position)             // we have reached the first path to the objective!
    {                                                                     // not necessarilly the shortest
      printf("YO WE GOT THIS!");
      return;
    }

    if (!current_node->isDiscovered)
    {
      current_node->isDiscovered = true;

      //it is waaaay much better to change this whole section a For each loop
      if (grid.IsCaseAccessible(current_node->position.x - 1, current_node->position.y))
      {

        current_node->case_up_node = tree.CreateNewNode(current_node->position.x - 1, current_node->position.y, current_node);
        DFS_stack.push(current_node->case_up_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x, current_node->position.y - 1))
      {
        current_node->case_left_node = tree.CreateNewNode(current_node->position.x, current_node->position.y - 1, current_node);
        DFS_stack.push(current_node->case_left_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x + 1, current_node->position.y))
      {
        current_node->case_down_node = tree.CreateNewNode(current_node->position.x + 1, current_node->position.y, current_node);
        DFS_stack.push(current_node->case_down_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x, current_node->position.y + 1))
      {
        current_node->case_right_node = tree.CreateNewNode(current_node->position.x, current_node->position.y + 1, current_node);
        DFS_stack.push(current_node->case_right_node);
      }

      renderer.Clear(0x00, 0x00, 0x00);

      // draw everything here
      grid.RenderGrid();

      Draw_path(grid, current_node);
      SDL_Delay(delayStepTime);

      renderer.UpdateScreen();

    }
  }

} /* DFS_iterati */




void SA::DFS_iterative_elementary(Grid& grid, GeneralTree& tree, std::stack< GridCaseNode* >& DFS_stack)
{

    GridCaseNode* current_node = DFS_stack.top();
    DFS_stack.pop();

    if (current_node->position == grid.GetEndCase().position) return;     // we have reached the first path to the objective!
                                                                          // not necessarilly the shortest

    if (!current_node->isDiscovered)
    {
      current_node->isDiscovered = true;

      //it is waaaay much better to change this whole section a For each loop
      if (grid.IsCaseAccessible(current_node->position.x - 1, current_node->position.y))
      {

        current_node->case_up_node = tree.CreateNewNode(current_node->position.x - 1, current_node->position.y, current_node);
        DFS_stack.push(current_node->case_up_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x, current_node->position.y - 1))
      {
        current_node->case_left_node = tree.CreateNewNode(current_node->position.x, current_node->position.y - 1, current_node);
        DFS_stack.push(current_node->case_left_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x + 1, current_node->position.y))
      {
        current_node->case_down_node = tree.CreateNewNode(current_node->position.x + 1, current_node->position.y, current_node);
        DFS_stack.push(current_node->case_down_node);
      }

      if (grid.IsCaseAccessible(current_node->position.x, current_node->position.y + 1))
      {
        current_node->case_right_node = tree.CreateNewNode(current_node->position.x, current_node->position.y + 1, current_node);
        DFS_stack.push(current_node->case_right_node);
      }

    }

}





void SA::Draw_path(Grid& grid, GridCaseNode* node)
{
  while(node != NULL)
  {
    grid.RenderGridCase(node->position.x, node->position.y, 0, 255, 0, 0xFF);
    node = node->came_from;
  }
}

// Depth Limited Search
//void DLS_iterative(const Grid& grid, int depth_limit)
//{
//  std::stack< Vector2D > DFS_stack;
//
//  // usefull for determining discovered cases (discovered = a case that the algorithm walked through before)
//  // according to the chosen data structure, there is a trade-off between space and time complexity
//  GeneralTree tree();
//
//  Vector2D current_case = Vector2D(grid.GetStartCase().posX, grid.GetStartCase().posY);
//  Vector2D came_from = NULL;
//
//  DFS_stack.push(current_case);
//
//  while (!DFS_stack.empty())
//  {
//    Vector2D current_case = DFS_stack.pop();
//
//    // if this node hasn't yet been developed AND node depth is below LIMIT depth
//    if ( ( tree.IsCaseDeveloped(current_case) == false ) && ( tree.GetNodeDepth(current_case) < depth_limit ) )
//    {
//      tree.CreateNewNode(current_case, came_from);
//
//      for (size_t i = 0; i < MAX_NEXT_DISCOVERABLE_CASES; i++)
//      {
//        if (grid.GetCasesToDiscoverNext()[i] != NULL)
//        {
//          DFS_stack.push(grid_case);
//        }
//      }
//    }
//  }
//}

// A* Algorithm with custom heuristic function
// A* is similar to Djikstra algorithm when heuristic function is set to return 0
//void AStar(Grid& grid, int (*heuristic)(GridCase)/*heuristic function pointer here*/)
//{
//  std::priority_queue<Vector2D> cases_to_develop;   // priority queue according to SCORE criteria
//
//  GeneralTree tree(start_from);
//
//  Vector2D current_case = start_from;
//
//  current_case.came_from = NULL;
//  current_case.best_known_cost_from_root_to_this_case = 0;  // it is set by default to +infinity
//
//  current_case.score = current_case.best_known_cost_from_root_to_this_case + heuristic(current_case);
//
//  cases_to_develop.push(current_case);
//
//  while (!cases_to_develop.empty())
//  {
//    current_case = cases_to_develop.pop();    // case having lowest SCORE
//    if (current_case == grid.GetEndCase())    // WE HAVE REACHED THE OBJECTIVE!
//      return;
//
//    // This is the --horrible-- implementation of : For each neighbor node
//
//    For each neighbor to the current_case (UP -> LEFT -> DOWN -> RIGHT)
//      IF this_path_to_this_neighbor IS BETTER than previous_path_to_this_neighbor THEN:
//        neighbor.score = (current_case.best_known_cost_from_root_to_this_case + 1) + heuristic(neighbor);
//        neighbor.came_from = current_case
//        IF neighbor IS NOT IN cases_to_develop THEN
//          cases_to_develop.push(neighbor);
//  }
//
//}




#endif
