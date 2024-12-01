#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>
#include <vector>

namespace aoc::aoc2024 {

struct Day1 : public IDay {
  Day1(IPuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  std::vector<int> group_a_;
  std::vector<int> group_b_;
};

}  // namespace aoc::aoc2024
