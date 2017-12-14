#include <iostream>
#include <string>
#include <sstream>

#include "range/v3/algorithm/for_each.hpp"
#include "range/v3/istream_range.hpp"

#include "HexCoordinates.cpp"

using namespace std;

int main() {
  string input;
  getline(cin, input);
  istringstream directions { input };

  HexCoordinates position { 0, 0, 0 };

  ranges::for_each(ranges::istream<Direction>(directions),
    [&position] (const Direction& direction) {
      position.move(direction);
    });

  cout << getDistance(position) << endl;

  return EXIT_SUCCESS;
}
