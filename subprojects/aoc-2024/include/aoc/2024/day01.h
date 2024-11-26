#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

namespace aoc::aoc2024 {

struct Day1 : public IDay {
  Day1(IPuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  IPuzzleReader::Lines lines_;
};

}  // namespace aoc::aoc2024
