#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>
#include <vector>

namespace aoc::aoc2024 {

struct Day2 : public IDay {
  Day2(IPuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  std::vector<std::vector<int>> reports_;
};

}  // namespace aoc::aoc2024
