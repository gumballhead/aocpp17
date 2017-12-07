#ifndef DIRECTION_HPP
#define DIRECTION_HPP

enum Direction { UP, RIGHT, DOWN, LEFT };

inline Direction& operator ++ (Direction& direction) {
  direction = direction == LEFT ? UP
    : static_cast<Direction>(static_cast<int>(direction) + 1);

  return direction;
}

inline Direction& operator -- (Direction& direction) {
  direction = direction == UP ? LEFT
    : static_cast<Direction>(static_cast<int>(direction) - 1);

  return direction;
}

inline Direction operator ++ (Direction& direction, int ignored) {
  const Direction result = direction;
  ++direction;

  return result;
}

inline Direction operator -- (Direction& direction, int ignored) {
  const Direction result = direction;
  --direction;

  return result;
}

#endif
