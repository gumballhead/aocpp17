#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<int> jumps {
    istream_iterator<int>(cin),
    istream_iterator<int>()
  };

  const int size = jumps.size();
  int i = 0;
  int step = 0;

  while (i >= 0 && i < size) {
    int& jump = jumps.at(i);
    i += jump;

    if (jump >= 3) {
      jump--;
    } else {
      jump++;
    }

    step++;
  }

  cout << step << endl;

  return EXIT_SUCCESS;
}
