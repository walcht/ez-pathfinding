#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include "Common.hpp"

struct GridCaseNode {
  GridCaseNode* came_from       = NULL;                 // pointer to parent node; usefull for backtracking

  GridCaseNode* case_up_node    = NULL;                 // first child  (from left to right)
  GridCaseNode* case_left_node  = NULL;                 // second child (from left to right)
  GridCaseNode* case_down_node  = NULL;                 // third child  (from left to right)
  GridCaseNode* case_right_node  = NULL;                // fourth child (from left to right)

  Vector2D      position;                               // which grid case does this node reference?

  int           gScore;                                 // shortest know path cost (so far) from root to this node
  int           score;                                  // score = gScore + heuristic(this)

  bool          isDiscovered    = false;                // did we develop the children of this node?

  int           depth           = 0;                    // depth of this node in tree structure (there is surelly a much better way to do this)
};

class GeneralTree {

private:

  GridCaseNode*   _root         = NULL;
  int             _depth        = 0;                    // tree depth

public:

  /////////////////////////////////////////////////////////////////////////////////////
  // CONSTRUCTORS
  /////////////////////////////////////////////////////////////////////////////////////

  GeneralTree();                                        // default constructor DOES NOT create root node
  GeneralTree(Vector2D rootPosition);                   // Creates root node



  /////////////////////////////////////////////////////////////////////////////////////
  // DESTRUCTOR
  /////////////////////////////////////////////////////////////////////////////////////

  ~GeneralTree();                                       // recursively delete the whole tree structure



  /////////////////////////////////////////////////////////////////////////////////////
  // MODIFIERS
  /////////////////////////////////////////////////////////////////////////////////////

  GridCaseNode* CreateNewNode(Vector2D pPosition, GridCaseNode* cameFrom);          // creates any node
  GridCaseNode* CreateNewNode(int x, int y, GridCaseNode* cameFrom);                // creates any node


  /////////////////////////////////////////////////////////////////////////////////////
  // GETTERS
  /////////////////////////////////////////////////////////////////////////////////////

  const int GetDepth() const;                          // returns tree depth



private:


  void deleteTreeRecursive(GridCaseNode* node);       // delete the whole tree whose root is node
  void updateDepth(int depth);                        // update tree depth

};

#endif
