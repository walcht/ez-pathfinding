#ifndef GRID_H
#define GRID_H

#include <vector>
#include <random>

#include "Common.hpp"
#include "Renderer.hpp"

struct GridCase {
  Vector2D  position;                           // position in the grid
  bool      isWall      = false;                // is this grid case a wall?

  GridCase(Vector2D& pPosition, bool pWall = false);
  GridCase(int x, int y, bool pWall = false);
  GridCase();
};

class Grid {
private:
  std::vector< std::vector<GridCase> > _grid;   // data structure wholding grid cases information

  int           _width;                         // width of the grid in: number of horizontal cases
  int           _height;                        // height of the grid in: number of vertical cases
                                                // currently only squared grids are supported

  int           _line_width = 2;                // vertical and horizontal width of the line that seperates grid cases
  int           _case_size;                     // how large is the SQUARED case?

  GridCase      _startCase;
  GridCase      _endCase;

  Renderer&     _renderer;                      //

public:
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // CONSTRUCTORS
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Grid(Renderer &renderer, int width, int height);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // GETTERS
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  const int GetWidth() const {return _width;}
  const int GetHeight() const {return _height;}
  Renderer& GetAttachedRenderer();                              // Renderer attached to this grid
  GridCase& GetStartCase();                         // returns case from which pathfinding algorithm starts
  GridCase& GetEndCase();                           // returns case which pathfinding algorithm aims to reach
  const GridCase& GetStartCase() const;                         // returns case from which pathfinding algorithm starts
  const GridCase& GetEndCase() const;                           // returns case which pathfinding algorithm aims to reach

  bool IsCaseAccessible(Vector2D pPosition) const;
  bool IsCaseAccessible(int x, int y) const;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // SETTERS
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void SetStartCase(GridCase startCase);
  void SetEndCase(GridCase endCase);

  void RandomizeGrid(float frequency, int seed);

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // OPERATORS
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  GridCase& operator() (int x, int y);
  const GridCase& operator() (int x, int y) const;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // DRAWERS
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void DrawStartCase();
  void DrawEndCase();

  void RenderGrid();
  void RenderGridCase(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0xFF);

};

#endif
