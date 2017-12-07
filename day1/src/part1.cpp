#include <iostream>
#include <functional>
#include <string>

#include "range/v3/numeric/accumulate.hpp"
#include "range/v3/view/adjacent_filter.hpp"
#include "range/v3/view/tail.hpp"
#include "range/v3/view/transform.hpp"

using namespace std;
namespace view = ranges::view;

int main() {
  string input;
  getline(cin, input);

  auto numbers = input
    | view::adjacent_filter(equal_to<char>())
    | view::transform([] (const char& number) { return number - '0'; });

  // adjacent_filter always includes the first element; drop if not equal to last element
  const unsigned short total = input.front() == input.back()
    ? ranges::accumulate(numbers, 0)
    : ranges::accumulate(view::tail(numbers), 0);

  cout << total << endl;

  return EXIT_SUCCESS;
}
