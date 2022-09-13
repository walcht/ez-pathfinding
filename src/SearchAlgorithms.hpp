#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include "SearchAlgorithmBase.hpp"
#include "Common.hpp"
#include "Grid.hpp"
#include "Tree.hpp"

#include <stack>
#include <queue>

// SA stands for: Search Algorithms
namespace SA {
  
  class DFS : public SearchAlgorithmBase
  {
    private:
      std::stack< GridCaseNode* > DFS_stack;
        
    public:
      DFS(Grid& _grid);

      bool iterative_verify() const;
      void iterative_elementary();
  };

  void Draw_path(Grid& grid, GridCaseNode* node);
  //

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // DEPTH FIRST SEARCH ALGORITHMS: DFS, DLS, HILL CLIMBING
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void HC_iterative_elementary_init(Grid& grid, GeneralTree& tree, std::priority_queue< GridCaseNode* >& HC_queue);
  bool HC_iterative_elementary_verify(Grid& grid, GeneralTree& tree, std::priority_queue< GridCaseNode* >& HC_queue);
  void HC_iterative_elementary(Grid& grid, GeneralTree& tree, std::priority_queue< GridCaseNode* >& HC_queue, int (*heuristic)(Vector2D&));

  //void DLS_iterative(const Grid& grid, int depth_limit);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // BREADTH-FIRST SEARCH ALGORITHMS: BFS
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void BFS_iterative_elementary_init(Grid& grid, GeneralTree& tree, std::queue< GridCaseNode* >& BFS_queue);
  bool BFS_iterative_elementary_verify(Grid& grid, GeneralTree& tree, std::queue< GridCaseNode* >& BFS_queue);
  void BFS_iterative_elementary(Grid& grid, GeneralTree& tree, std::queue< GridCaseNode* >& BFS_queue);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // A* ALGORITHMS
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


} /* SA */





void SA::Draw_path(Grid& grid, GridCaseNode* node)
{
  while(node != NULL)
  {
    grid.RenderGridCase(node->position.x, node->position.y, 0, 0, 0xFF, 0xFF);
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

void SA::BFS_iterative_elementary_init(Grid& grid, GeneralTree& tree, std::queue< GridCaseNode* >& BFS_queue)
{
  BFS_queue.push(tree.CreateNewNode(grid.GetStartCase().position, NULL));
}

bool SA::BFS_iterative_elementary_verify(Grid& grid, GeneralTree& tree, std::queue< GridCaseNode* >& BFS_queue)
{
  if (BFS_queue.empty()) return false;
  if (BFS_queue.front()->position == grid.GetEndCase().position) return false;
  return true;
}

void SA::BFS_iterative_elementary(Grid& grid, GeneralTree& tree, std::queue< GridCaseNode* >& BFS_queue)
{
  GridCaseNode* current_node = BFS_queue.front();
  BFS_queue.pop();

  grid(current_node->position).isDeveloped = true;

  if (  grid.IsCaseAccessible(current_node->position.x, current_node->position.y + 1)
        && !grid(current_node->position.x, current_node->position.y + 1).isDeveloped  )
  {
    current_node->case_right_node = tree.CreateNewNode(current_node->position.x, current_node->position.y + 1, current_node);
    BFS_queue.push(current_node->case_right_node);
  }

  if (  grid.IsCaseAccessible(current_node->position.x + 1, current_node->position.y)
        && !grid(current_node->position.x + 1, current_node->position.y).isDeveloped  )
  {
    current_node->case_down_node = tree.CreateNewNode(current_node->position.x + 1, current_node->position.y, current_node);
    BFS_queue.push(current_node->case_down_node);
  }

  if (  grid.IsCaseAccessible(current_node->position.x, current_node->position.y - 1)
        && !grid(current_node->position.x, current_node->position.y - 1).isDeveloped  )
  {
    current_node->case_left_node = tree.CreateNewNode(current_node->position.x, current_node->position.y - 1, current_node);
    BFS_queue.push(current_node->case_left_node);
  }

  if (  grid.IsCaseAccessible(current_node->position.x - 1, current_node->position.y)
        && !grid(current_node->position.x - 1, current_node->position.y).isDeveloped  )
  {
    current_node->case_up_node = tree.CreateNewNode(current_node->position.x - 1, current_node->position.y, current_node);
    BFS_queue.push(current_node->case_up_node);
  }

}


//void SA::HC_iterative_elementary(Grid& grid, GeneralTree& tree, std::priority_queue< GridCaseNode* >& HC_queue, int (*heuristic)(Vector2D&))
//{
//  GridCaseNode* current_node = HC_queue.front();
//  HC_queue.pop();
//
//  grid(current_node->position).isDeveloped = true;
//
//  if (  grid.IsCaseAccessible(current_node->position.x, current_node->position.y + 1)
//        && !grid(current_node->position.x, current_node->position.y + 1).isDeveloped  )
//  {
//    current_node->case_right_node = tree.CreateNewNode(current_node->position.x, current_node->position.y + 1, current_node);
//    HC_queue.push(current_node->case_right_node);
//  }
//
//  if (  grid.IsCaseAccessible(current_node->position.x + 1, current_node->position.y)
//        && !grid(current_node->position.x + 1, current_node->position.y).isDeveloped  )
//  {
//    current_node->case_down_node = tree.CreateNewNode(current_node->position.x + 1, current_node->position.y, current_node);
//    HC_queue.push(current_node->case_down_node);
//  }
//
//  if (  grid.IsCaseAccessible(current_node->position.x, current_node->position.y - 1)
//        && !grid(current_node->position.x, current_node->position.y - 1).isDeveloped  )
//  {
//    current_node->case_left_node = tree.CreateNewNode(current_node->position.x, current_node->position.y - 1, current_node);
//    HC_queue.push(current_node->case_left_node);
//  }
//
//  if (  grid.IsCaseAccessible(current_node->position.x - 1, current_node->position.y)
//        && !grid(current_node->position.x - 1, current_node->position.y).isDeveloped  )
//  {
//    current_node->case_up_node = tree.CreateNewNode(current_node->position.x - 1, current_node->position.y, current_node);
//    HC_queue.push(current_node->case_up_node);
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
