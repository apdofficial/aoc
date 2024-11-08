#include <aoc/2022/day04.h>
#include <aoc/common/range/range.h>

#include <algorithm>
#include <sstream>

namespace {

// read string like 1-2,3-4 into pair of ranges
auto Parse(std::string const& line) -> std::pair<aoc::Range, aoc::Range> {
  char delimiter{};
  aoc::Range r1{};
  aoc::Range r2{};
  std::istringstream iss{line};
  iss >> r1 >> delimiter >> r2;
  return {r1, r2};
}

}  // namespace
namespace aoc::aoc2022 {

Day4::Day4(PuzzleReader::Lines const& lines) : lines_(lines) {}

auto Day4::SolvePart1() -> Puzzle::Part1 {
  int count = std::ranges::count_if(lines_, [](std::string const& line) {
    auto [r1, r2] = Parse(line);
    return r1.is_sub_range(r2) || r2.is_sub_range(r1);
  });
  return count;
}

auto Day4::SolvePart2() -> Puzzle::Part2 {
  int count = std::ranges::count_if(lines_, [](std::string const& line) {
    auto [r1, r2] = Parse(line);
    return r1.intersects(r2) || r2.intersects(r1);
  });
  return count;
}

};  // namespace aoc::aoc2022
