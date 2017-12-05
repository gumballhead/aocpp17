#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>

#include "range/v3/getlines.hpp"
#include "range/v3/istream_range.hpp"
#include "range/v3/to_container.hpp"
#include "range/v3/algorithm/find_if.hpp"
#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/cartesian_product.hpp"
#include "range/v3/view/transform.hpp"

#include <typeinfo>

using namespace std;
namespace view = ranges::view;

int main() {
  auto rows = ranges::getlines(cin) | view::transform([] (const string& line) {
    istringstream row { line };
    return ranges::istream<int>(row) | ranges::to_vector;
  });

  auto sums = view::transform(rows, [] (const vector<int> &row) {
    const auto found = ranges::find_if(view::cartesian_product(row, row),
      [] (const tuple<int, int>& pair) {
        const auto [first, second] = pair;
        const bool found = first > second && first % second == 0;
        return found;
      });

    const auto [first, second] = *found.get_unsafe();
    return first / second;
  });

  cout << ranges::accumulate(sums, 0) << endl;

  return EXIT_SUCCESS;
}
