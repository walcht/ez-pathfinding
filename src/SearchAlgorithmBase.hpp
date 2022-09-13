#ifndef SEARCH_ALGORITHM_BASE_H
#define SEARCH_ALGORITHM_BASE_H

#include "Common.hpp"
#include "Grid.hpp"
#include "Tree.hpp"

class SearchAlgorithmBase
{
  protected:
    Grid& mainGrid;
    GeneralTree tree;
    GridCaseNode& currentNode;

  public:
    SearchAlgorithmBase(Grid& _mainGrid);

    virtual void iterative_elementary() = 0;
    virtual bool iterative_verify() const = 0;
    virtual void iterative()
    {
      while (iterative_verify())
        iterative_elementary();
    }

    GridCaseNode& CurrentNode() {return currentNode;}
};

#endif

