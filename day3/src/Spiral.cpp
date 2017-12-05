#include <cmath>

#include "Spiral.hpp"

using namespace std;

void Spiral::move() {
  switch (bearing) {
    case EAST: {
      coordinates.x++;
      break;
    }

    case NORTH: {
      coordinates.y++;
      break;
    }

    case WEST: {
      coordinates.x--;
      break;
    }

    case SOUTH: {
      coordinates.y--;
      break;
    }
  }
}

Coordinates Spiral::operator() () {
  if (i == pow(2 * size + 1, 2)) {
    size++;
  }

  if (bearing == EAST && coordinates.x == size ||
    bearing == NORTH && coordinates.y == size ||
    bearing == WEST && -coordinates.x == size ||
    bearing == SOUTH && -coordinates.y == size) {
    bearing--;
  }

  move();
  i++;

  return coordinates;
}
