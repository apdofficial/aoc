#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

namespace aoc::aoc2022 {

struct Day2 : IDay {
  using OptionType = char;
  enum class Player1 : OptionType {
    ROCK = 'A',
    PAPER = 'B',
    SCISSORS = 'C',
  };

  enum class Player2 : OptionType {
    ROCK = 'X',
    PAPER = 'Y',
    SCISSORS = 'Z',
  };

  enum class Strategy : OptionType {
    LOSE = 'X',
    DRAW = 'Y',
    WIN = 'Z',
  };

  using Round = std::pair<Player1, Player2>;
  using Rounds = std::vector<Round>;

  Day2(PuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  Rounds rounds_{};
};

}  // namespace aoc::aoc2022
