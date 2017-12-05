using namespace std;

struct Coordinates {
  int x;
  int y;
};

inline int getDistance(Coordinates coordinates) {
  return abs(coordinates.x) + abs(coordinates.y);
}
