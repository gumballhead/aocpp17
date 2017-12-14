#include "HexCoordinates.hpp"

void HexCoordinates::move(const Direction& direction) {
  switch (direction) {
    case Direction::North:
      y++;
      z--;
      break;

    case Direction::NorthEast:
      x++;
      z--;
      break;

    case Direction::SouthEast:
      x++;
      y--;
      break;

    case Direction::South:
      y--;
      z++;
      break;

    case Direction::SouthWest:
      x--;
      z++;
      break;

    case Direction::NorthWest:
      y++;
      x--;
      break;
  }
}

int getDistance(const HexCoordinates& coordinates) {
  return (abs(coordinates.x) + abs(coordinates.y) + abs(coordinates.z)) / 2;
}
