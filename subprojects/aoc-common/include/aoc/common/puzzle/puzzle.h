#pragma once

#include <string>
#include <variant>

namespace aoc {

class Puzzle {
 public:
  using NumberType = int;
  using TextType = std::string;
  using Part1 = std::variant<TextType, NumberType>;
  using Part2 = std::variant<TextType, NumberType>;
  Part1 part1;
  Part2 part2;
};

}  // namespace aoc
