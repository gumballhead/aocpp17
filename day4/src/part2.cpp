#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>

#include "range/v3/getlines.hpp"
#include "range/v3/istream_range.hpp"
#include "range/v3/algorithm/all_of.hpp"
#include "range/v3/algorithm/count_if.hpp"
#include "range/v3/view/transform.hpp"

using namespace std;
namespace view = ranges::view;

int main() {
  auto lines = ranges::getlines(cin);

  const int valid = ranges::count_if(lines, [] (const string& line) {
    unordered_set<string> phrase;
    istringstream row { line };

    auto words = ranges::istream<string>(row) | view::transform([] (string& word) {
      sort(word.begin(), word.end());
      return word;
    });

    return ranges::all_of(words, [&phrase] (const string& word) {
      const bool unique = phrase.find(word) == phrase.end();
      if (unique) { phrase.insert(word); }
      return unique;
    });
  });

  cout << valid << endl;

  return EXIT_SUCCESS;
}
