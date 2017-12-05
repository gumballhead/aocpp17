#include <iostream>
#include <string>

#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/drop.hpp"
#include "range/v3/view/take.hpp"
#include "range/v3/view/zip_with.hpp"

using namespace std;
namespace view = ranges::view;

int main() {
  string input;
  getline(cin, input);
  const size_t size = input.size() / 2;

  auto numbers = view::zip_with([] (const char& first, const char& second) {
    return first == second ? (first - '0') * 2 : 0;
  }, view::take(input, size), view::drop(input, size));

  cout << ranges::accumulate(numbers, 0) << endl;

  return EXIT_SUCCESS;
}
