#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int hashInts(const vector<int>& vec) {
  return accumulate(vec.begin(), vec.end(), 17,
    [] (const int &hash, const int& number) {
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

  while (true) {
    const auto max = max_element(banks.begin(), banks.end());
    int i = distance(banks.begin(), max);
    int value = banks[i];
    banks[i] = 0;

    do {
      const int index = (i + value) % size;
      ++banks.at(index);
    } while (--value);

    const int state = hashInts(banks);

    if (find(states.begin(), states.end(), state) == states.end()) {
      states.push_back(state);
    } else {
      break;
    }
  }

  cout << states.size() << endl;

  return EXIT_SUCCESS;
}
