#include <string>
#include <unordered_map>

using namespace std;

enum class Direction {
  North,
  NorthEast,
  SouthEast,
  South,
  SouthWest,
  NorthWest
};

const unordered_map<string, Direction> lookup {
  {"n", Direction::North},
  {"ne", Direction::NorthEast},
  {"se", Direction::SouthEast},
  {"s", Direction::South},
  {"sw", Direction::SouthWest},
  {"nw", Direction::NorthWest}
};

Direction parseDirection(const string& code) {
  return lookup.at(code);
}

istream & operator >> (istream &input, Direction &direction) {
  string code;
  getline(input, code, ',');

  if (!empty(code)) direction = parseDirection(code);

  return input;
}
