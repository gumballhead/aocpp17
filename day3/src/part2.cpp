#include <iostream>
#include <unordered_map>
#include <utility>

#include "range/v3/algorithm/find_if.hpp"
#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/generate.hpp"
#include "range/v3/view/remove_if.hpp"
#include "range/v3/view/slice.hpp"
#include "range/v3/view/transform.hpp"

#include "Spiral.cpp"

using namespace std;
namespace view = ranges::view;

int main(int argc, char** argv) {
  const int input = atoi(argv[1]);
  Spiral spiral;

  unordered_map<Point, int, PointHash> values {
    {  spiral(), 1 }
  };

  auto position = ranges::find_if(view::generate(spiral),
    [&input, &values] (const Point& position) {
      auto neighborsValues = view::generate(Spiral(position))
        | view::slice(1, 9)

        | view::remove_if([&values] (const Point& neighbor) {
            return values.find(neighbor) == values.end();
          })

        | view::transform([&values] (const Point& neighbor) {
            return values.at(neighbor);
          });

      const int value = ranges::accumulate(neighborsValues, 0);
      values.insert({ position, value });

      return value > input;
    });

  const int value = values.at(*position.get_unsafe());
  cout << value << endl;

  return EXIT_SUCCESS;
}
