#include <aoc/2024/day01.h>

#include <algorithm>
#include <cmath>
#include <map>
#include <sstream>

namespace aoc::aoc2024 {

Day1::Day1(IPuzzleReader::Lines const& lines) {
  for (auto const& line : lines) {
    group_a_.push_back(0);
    group_b_.push_back(0);
    std::istringstream is{line};
    is >> group_a_.back() >> group_b_.back();
  }
}

auto Day1::SolvePart1() -> Puzzle::Part1 {
  std::ranges::sort(group_a_);
  std::ranges::sort(group_b_);
  int total_distance{};
  for (size_t i{}; i < group_a_.size(); ++i) {
    total_distance += std::abs(group_a_[i] - group_b_[i]);
  }
  return total_distance;
}

auto Day1::SolvePart2() -> Puzzle::Part2 {
  std::map<int, int> cache{};
  int similartity{};
  for (size_t i{}; i < group_a_.size(); ++i) {
    auto const id = group_a_[i];
    if (cache.contains(id)) {
      similartity += cache[id];
      continue;
    }
    cache[id] = id * std::ranges::count(group_b_, id);
    similartity += cache[id];
  }
  return similartity;
}

}  // namespace aoc::aoc2024
