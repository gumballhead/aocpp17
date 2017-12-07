#include <iostream>
#include <unordered_map>
#include <utility>

#include "range/v3/algorithm/find_if.hpp"
#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/for_each.hpp"
#include "range/v3/view/generate.hpp"
#include "range/v3/view/iota.hpp"
#include "range/v3/view/remove_if.hpp"
#include "range/v3/view/transform.hpp"

#include "Spiral.cpp"

using namespace std;
namespace view = ranges::view;

auto neighbors(const Coordinates& coordinates) {
  return view::for_each(view::iota(-1, 2), [&coordinates] (const int x) {
    return view::for_each(view::iota(-1, 2), [&coordinates, x] (const int y) {
      return ranges::yield_if(!(x == 0 && y == 0), Coordinates {
        coordinates.x + x,
        coordinates.y + y
      });
    });
  });
}

int main(int argc, char** argv) {
  const int input = atoi(argv[1]);

  unordered_map<Coordinates, int, CoordinatesHash> values {
    { Coordinates { 0, 0 }, 1 }
  };

  auto coordinates = ranges::find_if(view::generate(Spiral()),
    [&input, &values] (const Coordinates& coordinates) {
      auto neighborsValues = neighbors(coordinates)
        | view::remove_if([&values] (const Coordinates& neighbor) {
            return values.find(neighbor) == values.end();
          })

        | view::transform([&values] (const Coordinates& neighbor) {
            return values.at(neighbor);
          });

      const int value = ranges::accumulate(neighborsValues, 0);
      values.insert({ coordinates, value });

      return value > input;
    });

  const int value = values.at(*coordinates.get_unsafe());
  cout << value << endl;

  return EXIT_SUCCESS;
}
