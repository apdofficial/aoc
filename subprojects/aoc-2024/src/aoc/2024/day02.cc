#include <aoc/2024/day02.h>

#include <algorithm>
#include <ranges>
#include <string>

namespace {

auto IsValid(std::vector<int> const& report) -> bool {
  int tmp{*report.begin()};
  int prev_diff{tmp - *std::next(report.begin())};
  auto pred = [&tmp, &prev_diff](int x) {
    auto const diff = tmp - x;
    auto const is_valid =
        !((diff ^ prev_diff) < 0) && std::abs(diff) >= 1 && std::abs(diff) <= 3;
    prev_diff = diff;
    tmp = x;
    return is_valid;
  };
  return std::all_of(std::next(report.begin()), report.end(), pred);
}
}  // namespace

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
  return std::ranges::fold_left(reports_, 0, [](int acc, auto const& report) {
    return acc + IsValid(report);
  });
}

auto Day2::SolvePart2() -> Puzzle::Part2 {
  auto pred = [](int acc, std::vector<int> const& report) {
    for (int i{}; i < report.size(); ++i) {
      auto report_cpy = report;
      report_cpy.erase(report_cpy.begin() + i);
      if (IsValid(report_cpy)) {
        return acc + 1;
      }
    }
    return acc;
  };
  return std::ranges::fold_left(reports_, 0, pred);
}

}  // namespace aoc::aoc2024
