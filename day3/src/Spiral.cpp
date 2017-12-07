#include <cmath>

#include "Spiral.hpp"

using namespace std;

Spiral::Spiral(): Spiral(Point { 0, 0 }) {}
Spiral::Spiral(const Point& start): position(start), offset(start) {}

void Spiral::next() {
  switch (direction) {
    case RIGHT: {
      position.x++;
      break;
    }

    case UP: {
      position.y++;
      break;
    }

    case LEFT: {
      position.x--;
      break;
    }

    case DOWN: {
      position.y--;
      break;
    }
  }
}

Point Spiral::operator() () {
  const Point result = position;

  if (i == pow(2 * size + 1, 2)) {
    size++;
  }

  const auto [x, y] = offset;

  if (direction == RIGHT && position.x == x + size ||
    direction == UP && position.y == y + size ||
    direction == LEFT && position.x == x - size ||
    direction == DOWN && position.y == y - size) {
    direction--;
  }

  next();
  i++;

  return result;
}
