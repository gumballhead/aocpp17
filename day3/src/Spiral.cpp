#include <cmath>

#include "Spiral.hpp"

using namespace std;

Spiral::Spiral(): Spiral(Coordinates { 0, 0 }) {}
Spiral::Spiral(const Coordinates& start): coordinates(start), offset(start) {}

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
  const Coordinates result = coordinates;

  if (i == pow(2 * size + 1, 2)) {
    size++;
  }

  const auto [x, y] = offset;

  if (bearing == EAST && coordinates.x == x + size ||
    bearing == NORTH && coordinates.y == y + size ||
    bearing == WEST && coordinates.x == x - size ||
    bearing == SOUTH && coordinates.y == y - size) {
    bearing--;
  }

  move();
  i++;

  return result;
}
