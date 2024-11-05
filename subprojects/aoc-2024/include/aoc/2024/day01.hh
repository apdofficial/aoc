#pragma once

#include <aoc/common/day.hh>
#include <aoc/common/puzzle_reader.hh>

namespace aoc::aoc2024 {

struct Day1 : public IDay {

  Day1(PuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> int override;
  [[nodiscard]] auto SolvePart2() -> int override;

 private:
  PuzzleReader::Lines lines_;
};

}  // namespace aoc::aoc2022
