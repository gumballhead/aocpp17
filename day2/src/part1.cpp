#include <iostream>
#include <string>
#include <sstream>

#include "range/v3/getlines.hpp"
#include "range/v3/istream_range.hpp"
#include "range/v3/algorithm/minmax.hpp"
#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/transform.hpp"

using namespace std;
namespace view = ranges::view;

int main() {
  auto sums = ranges::getlines(cin) | view::transform([] (const string& line) {
    istringstream row { line };
    auto [min, max] = ranges::minmax(ranges::istream<int>(row));

    return max - min;
  });

  cout << ranges::accumulate(sums, 0) << endl;

  return EXIT_SUCCESS;
}
