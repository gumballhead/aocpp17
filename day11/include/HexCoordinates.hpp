#include "Direction.hpp"

// Using the cube coordinate system from:
// https://www.redblobgames.com/grids/hexagons/

struct HexCoordinates {
  int x;
  int y;
  int z;

  void move(const Direction& direction);
};
