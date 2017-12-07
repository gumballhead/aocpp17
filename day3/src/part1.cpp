#include <iostream>

#include "range/v3/view/drop.hpp"
#include "range/v3/view/generate.hpp"

#include "Spiral.cpp"

using namespace std;
namespace view = ranges::view;

int main(int argc, char** argv) {
  const int n = atoi(argv[1]);
  auto spiral = view::generate(Spiral()) | view::drop(n - 1);

  const Point position = *spiral.begin();
  cout << getDistance(position) << endl;

  return EXIT_SUCCESS;
}
