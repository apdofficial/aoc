#include <aoc/2022/day01.hh>

#include <algorithm>
#include <functional>
#include <numeric>
#include <span>

namespace {

std::vector<int> CalculateAndSortCalories(std::span<std::string> puzzle_lines) {
  std::vector<int> elf_calories{};
  int acc = 0;
  for (auto const& line : puzzle_lines) {
    try {
      acc += std::stoi(line);
    } catch (std::exception const& ex) {
      elf_calories.push_back(acc);
      acc = 0;
    }
  }
  if (acc > 0) {
    elf_calories.push_back(acc);
  }
  std::sort(elf_calories.begin(), elf_calories.end(), std::greater<>());
  return elf_calories;
}

}  // namespace

namespace aoc::aoc2022 {

Day1::Day1(PuzzleReader::Lines const& lines) : lines_(lines) {}

int Day1::SolvePart1() {
  return CalculateAndSortCalories(lines_).front();
}

int Day1::SolvePart2() {
  std::vector<int> elf_calories = CalculateAndSortCalories(lines_);
  return std::accumulate(elf_calories.begin(), elf_calories.begin() + 3, 0,
                         std::plus<>());
}

}  // namespace aoc::aoc2022
