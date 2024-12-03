#include <aoc/2022/day02.hh>
#include <format>
#include <numeric>
#include <stdexcept>

namespace {

int CalculateScore(aoc::aoc2022::Day2::Round const& round) {
  auto const p1 =
      static_cast<aoc::aoc2022::Day2::OptionType>(round.first) - 'A' + 1;
  auto const p2 =
      static_cast<aoc::aoc2022::Day2::OptionType>(round.second) - 'X' + 1;
  short constexpr kWinningScore{6};
  short constexpr kDrawScore{3};
  if (p1 == p2) {
    return p2 + kDrawScore;
  } else if (p1 == 1) {
    return p2 + (p2 == 3 ? 0 : kWinningScore);
  } else if (p1 == 2) {
    return p2 + (p2 == 1 ? 0 : kWinningScore);
  } else {
    return p2 + (p2 == 2 ? 0 : kWinningScore);
  }
}

aoc::aoc2022::Day2::Player2 CalculateMove(
    aoc::aoc2022::Day2::Player1 const& player1,
    aoc::aoc2022::Day2::Strategy const& strategy) {
  using namespace aoc::aoc2022;
  switch (strategy) {
    case Day2::Strategy::DRAW:
      return Day2::Player2(static_cast<Day2::OptionType>(player1) - 'A' + 'X');
    case Day2::Strategy::WIN:
      switch (player1) {
        case Day2::Player1::ROCK:
          return Day2::Player2::PAPER;
        case Day2::Player1::PAPER:
          return Day2::Player2::SCISSORS;
        case Day2::Player1::SCISSORS:
          return Day2::Player2::ROCK;
      }
    case Day2::Strategy::LOSE:
      switch (player1) {
        case Day2::Player1::ROCK:
          return Day2::Player2::SCISSORS;
        case Day2::Player1::PAPER:
          return Day2::Player2::ROCK;
        case Day2::Player1::SCISSORS:
          return Day2::Player2::PAPER;
      }
  }
  throw std::runtime_error(std::format(
      "Invalid strategy: {}", static_cast<Day2::OptionType>(strategy)));
}

}  // namespace

namespace aoc::aoc2022 {

Day2::Day2(PuzzleReader::Pairs const& pairs) {
  for (auto const& pair : pairs) {
    rounds_.emplace_back(Player1(pair.first), Player2(pair.second));
  }
}

int Day2::SolvePart1() {
  return std::accumulate(
      rounds_.begin(), rounds_.end(), 0,
      [](int acc, Round const& round) { return acc + CalculateScore(round); });
}

int Day2::SolvePart2() {
  auto acc_rounds = [](int acc, Round const& round) {
    Player1 const player1{round.first};
    Strategy const strategy{static_cast<OptionType>(round.second)};
    return acc + CalculateScore({player1, CalculateMove(player1, strategy)});
  };
  return std::accumulate(rounds_.begin(), rounds_.end(), 0, acc_rounds);
}

}  // namespace aoc::aoc2022
