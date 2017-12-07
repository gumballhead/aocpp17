#ifndef SPIRAL_HPP
#define SPIRAL_HPP

#include "Direction.hpp"
#include "Point.hpp"

class Spiral {
  private:
    Direction direction = RIGHT;
    Point position;
    const Point offset;
    unsigned int i = 1;
    unsigned int size = 0;
    void next();

  public:
    Spiral();
    Spiral(const Point& start);
    Point operator() ();
};

#endif
