#ifndef SPIRAL_HPP
#define SPIRAL_HPP

#include "Bearing.hpp"
#include "Coordinates.hpp"

class Spiral {
  private:
    Bearing bearing = EAST;
    Coordinates coordinates;
    const Coordinates offset;
    unsigned int i = 1;
    unsigned int size = 0;
    void move();

  public:
    Spiral();
    Spiral(const Coordinates& start);
    Coordinates operator() ();
};

#endif
