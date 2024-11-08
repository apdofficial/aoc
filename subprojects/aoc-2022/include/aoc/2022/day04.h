#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

namespace aoc::aoc2022 {

struct Day4 : IDay {
  Day4(PuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  PuzzleReader::Lines lines_{};
};

}  // namespace aoc::aoc2022
