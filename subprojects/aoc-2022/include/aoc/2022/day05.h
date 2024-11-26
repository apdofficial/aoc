#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

#include <vector>

namespace aoc::aoc2022 {

class Day5 : public IDay {
 public:
  using Stack = std::vector<char>;
  using Stacks = std::vector<Stack>;
  using StackId = int;
  using CrateId = int;

  struct Command {
    CrateId crate{};
    StackId src{};
    StackId dst{};
  };
  using Commands = std::vector<Command>;

  Day5(IPuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  Commands commands_{};
  Stacks stacks_{};
};

}  // namespace aoc::aoc2022
