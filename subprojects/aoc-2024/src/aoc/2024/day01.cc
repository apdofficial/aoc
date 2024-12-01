#include <aoc/2024/day01.h>

#include <algorithm>
#include <map>
#include <ranges>
#include <sstream>

namespace aoc::aoc2024 {

Day1::Day1(IPuzzleReader::Lines const& lines) {
  for (auto const& line : lines) {
    std::istringstream is{line};
    is >> group_a_.emplace_back() >> group_b_.emplace_back();
  }
}

auto Day1::SolvePart1() -> Puzzle::Part1 {
  std::ranges::sort(group_a_);
  std::ranges::sort(group_b_);
  return std::ranges::fold_left(
      std::views::zip(group_a_, group_b_), 0, [](int acc, auto pair) {
        return acc + std::abs(pair.first - pair.second);
      });
}

auto Day1::SolvePart2() -> Puzzle::Part2 {
  std::map<int, int> count{};
  for (auto const& id : group_b_) {
    ++count[id];
  }
  return std::ranges::fold_left(
      group_a_, 0, [&count](int acc, int id) { return acc + id * count[id]; });
}

}  // namespace aoc::aoc2024
