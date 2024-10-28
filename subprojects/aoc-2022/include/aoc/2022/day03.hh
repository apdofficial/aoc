#pragma once

#include <aoc/common/day.hh>
#include <aoc/common/puzzle_reader.hh>

namespace aoc::aoc2022 {

struct Day3 : IDay {
  Day3(PuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> int override;
  [[nodiscard]] auto SolvePart2() -> int override;

 private:
  PuzzleReader::Lines lines_;
};

}  // namespace aoc::aoc2022
