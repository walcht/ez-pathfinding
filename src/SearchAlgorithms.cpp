#include "SearchAlgorithms.hpp"

SA::DFS::DFS(Grid& _grid) : SearchAlgorithmBase(_grid)
{
  DFS_stack.push(tree.CreateNewNode(mainGrid.GetStartCase().position, NULL));
}

bool SA::DFS::iterative_verify() const
{
  if (DFS_stack.empty()) return false;    // no more nodes to develop
  if (DFS_stack.top()->position == mainGrid.GetEndCase().position) return false;  // destination is reached
  return true;
}

void SA::DFS::iterative_elementary()
{
  GridCaseNode* current_node = DFS_stack.top();
  currentNode = *current_node;

  DFS_stack.pop();
  mainGrid(current_node->position).isDeveloped = true;

  if (  mainGrid.IsCaseAccessible(current_node->position.x, current_node->position.y + 1)
        && !mainGrid(current_node->position.x, current_node->position.y + 1).isDeveloped  )
  {
    current_node->case_right_node = tree.CreateNewNode(current_node->position.x, current_node->position.y + 1, current_node);
    DFS_stack.push(current_node->case_right_node);
  }

  if (  mainGrid.IsCaseAccessible(current_node->position.x + 1, current_node->position.y)
        && !mainGrid(current_node->position.x + 1, current_node->position.y).isDeveloped  )
  {
    current_node->case_down_node = tree.CreateNewNode(current_node->position.x + 1, current_node->position.y, current_node);
    DFS_stack.push(current_node->case_down_node);
  }

  if (  mainGrid.IsCaseAccessible(current_node->position.x, current_node->position.y - 1)
      && !mainGrid(current_node->position.x, current_node->position.y - 1).isDeveloped  )
  {
    current_node->case_left_node = tree.CreateNewNode(current_node->position.x, current_node->position.y - 1, current_node);
    DFS_stack.push(current_node->case_left_node);
  }
  
  if (  mainGrid.IsCaseAccessible(current_node->position.x - 1, current_node->position.y)
      && !mainGrid(current_node->position.x - 1, current_node->position.y).isDeveloped  )
  {
    current_node->case_up_node = tree.CreateNewNode(current_node->position.x - 1, current_node->position.y, current_node);
    DFS_stack.push(current_node->case_up_node);
  }
}