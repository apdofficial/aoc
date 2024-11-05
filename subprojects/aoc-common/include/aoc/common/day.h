#pragma once

#include <aoc/common/puzzle/puzzle.h>

namespace aoc {

struct IDay {
  virtual ~IDay() = default;
  virtual auto SolvePart1() -> Puzzle::Part1 = 0;
  virtual auto SolvePart2() -> Puzzle::Part2 = 0;
};

}  // namespace aoc
