#pragma once

namespace aoc {

struct IDay {
  virtual ~IDay() = default;
  virtual auto SolvePart1() -> int = 0;
  virtual auto SolvePart2() -> int = 0;
};

}  // namespace aoc
