#include "Tree.hpp"

GeneralTree::GeneralTree() {}

GeneralTree::GeneralTree(Vector2D rootPosition)
{
  CreateNewNode(rootPosition, nullptr);
}

GeneralTree::~GeneralTree()
{
  deleteTreeRecursive(_root);
}

GridCaseNode* GeneralTree::CreateNewNode(Vector2D pPosition, GridCaseNode* cameFrom)
{
  GridCaseNode* new_node = new GridCaseNode;

  if (cameFrom == nullptr)
  {
    _root = new_node;
    new_node->position = pPosition;

    return new_node;
  }

  new_node->came_from = cameFrom;
  new_node->position = pPosition;
  new_node->depth = new_node->came_from->depth + 1;

  return new_node;
}

GridCaseNode* GeneralTree::CreateNewNode(int x, int y, GridCaseNode* cameFrom)
{
  GridCaseNode* new_node = new GridCaseNode;

  if (cameFrom == nullptr)
  {
    _root = new_node;
    new_node->position = Vector2D(x, y);

    return new_node;
  }

  new_node->came_from = cameFrom;
  new_node->position = Vector2D(x, y);
  new_node->depth = new_node->came_from->depth + 1;


  return new_node;
}

const int GeneralTree::GetDepth() const
{
  return _depth;
}

void GeneralTree::deleteTreeRecursive(GridCaseNode* node)
{
  if (node == nullptr) return;

  deleteTreeRecursive(node->case_up_node);
  deleteTreeRecursive(node->case_left_node);
  deleteTreeRecursive(node->case_down_node);
  deleteTreeRecursive(node->case_right_node);

  delete node;
}

void GeneralTree::updateDepth(int depth)
{
  if (depth > _depth) _depth = depth;
}
