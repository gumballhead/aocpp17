#include <iostream>
#include <string>
#include <sstream>

#include "range/v3/istream_range.hpp"
#include "range/v3/algorithm/max.hpp"
#include "range/v3/view/transform.hpp"

#include "HexCoordinates.cpp"

using namespace std;
namespace view = ranges::view;

int main() {
  string input;
  getline(cin, input);
  istringstream directions { input };

  HexCoordinates position{0, 0, 0};

  auto distances = ranges::istream<Direction>(directions) |
    view::transform([&position] (const Direction &direction) {
      position.move(direction);
      return getDistance(position);
    });

  cout << ranges::max(distances) << endl;

  return EXIT_SUCCESS;
}
