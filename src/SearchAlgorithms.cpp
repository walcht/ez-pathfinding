#include "SearchAlgorithms.hpp"
#include "SearchAlgorithmBase.hpp"

SA::DFS::DFS(Grid& _grid) : SearchAlgorithmBase(_grid)
{
  DFS_stack.push(tree.CreateNewNode(mainGrid.GetStartCase().position, NULL));
}

bool SA::DFS::iterative_verify() const
{
  if (DFS_stack.empty()) return false;    // no more nodes to develop
  if (currentNode->position == mainGrid.GetEndCase().position) return false;  // destination is reached
  return true;
}

void SA::DFS::iterative_elementary()
{
  currentNode = DFS_stack.top();

  DFS_stack.pop();
  mainGrid(currentNode->position).isDeveloped = true;

  if (  mainGrid.IsCaseAccessible(currentNode->position.x, currentNode->position.y + 1)
        && !mainGrid(currentNode->position.x, currentNode->position.y + 1).isDeveloped  )
  {
    currentNode->case_right_node = tree.CreateNewNode(currentNode->position.x, currentNode->position.y + 1, currentNode);
    DFS_stack.push(currentNode->case_right_node);
  }

  if (  mainGrid.IsCaseAccessible(currentNode->position.x + 1, currentNode->position.y)
        && !mainGrid(currentNode->position.x + 1, currentNode->position.y).isDeveloped  )
  {
    currentNode->case_down_node = tree.CreateNewNode(currentNode->position.x + 1, currentNode->position.y, currentNode);
    DFS_stack.push(currentNode->case_down_node);
  }

  if (  mainGrid.IsCaseAccessible(currentNode->position.x, currentNode->position.y - 1)
      && !mainGrid(currentNode->position.x, currentNode->position.y - 1).isDeveloped  )
  {
    currentNode->case_left_node = tree.CreateNewNode(currentNode->position.x, currentNode->position.y - 1, currentNode);
    DFS_stack.push(currentNode->case_left_node);
  }
  
  if (  mainGrid.IsCaseAccessible(currentNode->position.x - 1, currentNode->position.y)
      && !mainGrid(currentNode->position.x - 1, currentNode->position.y).isDeveloped  )
  {
    currentNode->case_up_node = tree.CreateNewNode(currentNode->position.x - 1, currentNode->position.y, currentNode);
    DFS_stack.push(currentNode->case_up_node);
  }
}


SA::BFS::BFS(Grid& _grid) : SearchAlgorithmBase(_grid)
{
    BFS_queue.push(tree.CreateNewNode(mainGrid.GetStartCase().position, NULL));
}

bool SA::BFS::iterative_verify() const
{
    if (BFS_queue.empty()) return false;
    if (BFS_queue.front()->position == mainGrid.GetEndCase().position) return false;
    return true;
}

void SA::BFS::iterative_elementary()
{
    GridCaseNode* currentNode = BFS_queue.front();
    BFS_queue.pop();

    mainGrid(currentNode->position).isDeveloped = true;

    if (  mainGrid.IsCaseAccessible(currentNode->position.x, currentNode->position.y + 1)
        && !mainGrid(currentNode->position.x, currentNode->position.y + 1).isDeveloped  )
    {
        currentNode->case_right_node = tree.CreateNewNode(currentNode->position.x, currentNode->position.y + 1, currentNode);
        BFS_queue.push(currentNode->case_right_node);
    }

    if (  mainGrid.IsCaseAccessible(currentNode->position.x + 1, currentNode->position.y)
        && !mainGrid(currentNode->position.x + 1, currentNode->position.y).isDeveloped  )
    {
        currentNode->case_down_node = tree.CreateNewNode(currentNode->position.x + 1, currentNode->position.y, currentNode);
        BFS_queue.push(currentNode->case_down_node);
    }

    if (  mainGrid.IsCaseAccessible(currentNode->position.x, currentNode->position.y - 1)
        && !mainGrid(currentNode->position.x, currentNode->position.y - 1).isDeveloped  )
    {
        currentNode->case_left_node = tree.CreateNewNode(currentNode->position.x, currentNode->position.y - 1, currentNode);
        BFS_queue.push(currentNode->case_left_node);
    }

    if (  mainGrid.IsCaseAccessible(currentNode->position.x - 1, currentNode->position.y)
        && !mainGrid(currentNode->position.x - 1, currentNode->position.y).isDeveloped  )
    {
        currentNode->case_up_node = tree.CreateNewNode(currentNode->position.x - 1, currentNode->position.y, currentNode);
        BFS_queue.push(currentNode->case_up_node);
    }
}