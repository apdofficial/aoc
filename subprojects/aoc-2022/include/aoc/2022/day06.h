#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

namespace aoc::aoc2022 {

class Day6 : public IDay {
 public:
  Day6(PuzzleReader::Lines const&) = delete;
  Day6(PuzzleReader::Line const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  PuzzleReader::Line line_{};
};

}  // namespace aoc::aoc2022
