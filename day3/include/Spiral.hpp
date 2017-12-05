#include "Bearing.hpp"
#include "Coordinates.hpp"

class Spiral {
  private:
    Bearing bearing = EAST;
    Coordinates coordinates = {0, 0};
    unsigned int i = 0;
    unsigned int size = 1;
    void move();

  public:
    Coordinates operator() ();
};
