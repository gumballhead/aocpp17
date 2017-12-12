#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int hashInts(const vector<int>& ints) {
  return accumulate(ints.begin(), ints.end(), 17,
    [] (const int& hash, const int& number) {
      return hash * 31 + number;
    });
}

int main() {
  vector<int> banks {
    istream_iterator<int>(cin),
    istream_iterator<int>()
  };

  vector<int> states {
    hashInts(banks)
  };

  const int size = banks.size();
  bool seen = false;

  while (true) {
    const auto max = max_element(banks.begin(), banks.end());
    const int i = distance(banks.begin(), max);
    int value = banks[i];
    banks[i] = 0;

    do {
      const int bank = (i + value) % size;
      ++banks.at(bank);
    } while (--value);

    const int state = hashInts(banks);

    if (find(states.begin(), states.end(), state) == states.end()) {
      states.push_back(state);
    } else if (!seen) {
      seen = true;
      states.clear();
      states.push_back(state);
    } else {
      break;
    }
  }

  cout << states.size() << endl;

  return EXIT_SUCCESS;
}
