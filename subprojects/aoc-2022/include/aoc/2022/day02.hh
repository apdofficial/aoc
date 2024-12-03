#pragma once

#include <aoc/common/day.hh>
#include <aoc/common/puzzle_reader.hh>

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

  Day2(PuzzleReader::Pairs const&);

  [[nodiscard]] auto SolvePart1() -> int override;
  [[nodiscard]] auto SolvePart2() -> int override;

 private:
  Rounds rounds_{};
};

}  // namespace aoc::aoc2022
