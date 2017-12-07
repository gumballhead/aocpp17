#ifndef POINT_HPP
#define POINT_HPP

using namespace std;

struct Point {
  int x;
  int y;
};

inline bool operator == (const Point& first, const Point& second) {
  return first.x == second.x && first.y == second.y;
}

class PointHash  {
  const hash<int> hashInt;

  public:
    size_t operator() (const Point& point) const {
      return 17 + (31 * hashInt(point.x)) + (31 * hashInt(point.y));
    }
};

inline int getDistance(const Point& point) {
  return abs(point.x) + abs(point.y);
}

#endif
