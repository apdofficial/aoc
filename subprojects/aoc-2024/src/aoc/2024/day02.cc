#include <aoc/2024/day02.h>

#include <algorithm>
#include <ranges>
#include <string>

namespace aoc::aoc2024 {

Day2::Day2(IPuzzleReader::Lines const& lines) {
  for (auto const& line : lines) {
    reports_.emplace_back();
    for (auto const& match : std::views::split(line, ' ')) {
      std::string str{match.begin(), match.end()};
      reports_.back().push_back(std::stoi(str));
    }
  }
}

auto Day2::SolvePart1() -> Puzzle::Part1 {
  int count{};
  for (auto const& report : reports_) {
    int tmp{*report.begin()};
    int prev_diff{tmp - *++report.begin()};
    count += std::all_of(++report.begin(), report.end(), [&tmp, &prev_diff](int x){
      auto const diff = tmp - x;
      if ((diff ^ prev_diff) < 0) {
        return false;
      }
      prev_diff = diff;
      tmp = x;
      return std::abs(diff) >= 1 && std::abs(diff) <= 3;
    });
  }
  return count;
}

auto Day2::SolvePart2() -> Puzzle::Part2 {
  return -1;
}

}  // namespace aoc::aoc2024
