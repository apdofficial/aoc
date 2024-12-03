#include <aoc/2024/day03.h>

#include <fmt/base.h>
#include <algorithm>
#include <regex>
#include <string>

namespace {

auto Multiply(std::string op) -> int {
  auto delim = op.find_first_of(',');
  auto a = op.substr(4, delim - 4);
  auto b = op.substr(delim + 1, op.find_last_of(')') - delim - 1);
  return std::stoi(a) * std::stoi(b);
}

}  // namespace

namespace aoc::aoc2024 {

Day3::Day3(IPuzzleReader::Lines const& lines) : lines_{lines} {}

auto Day3::SolvePart1() -> Puzzle::Part1 {
  return std::ranges::fold_left(lines_, 0, [](int acc, auto const& line) {
    std::regex re(R"(mul\(\d+,\d+\))");
    auto begin = std::sregex_iterator(line.begin(), line.end(), re);
    for (auto it{begin}; it != std::sregex_iterator(); ++it) {
      acc += Multiply(it->str());
    }
    return acc;
  });
}

auto Day3::SolvePart2() -> Puzzle::Part2 {
  bool multiply{true};
  return std::ranges::fold_left(lines_, 0, [&multiply](int acc, auto const& line) {
    std::regex re(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");
    auto begin = std::sregex_iterator(line.begin(), line.end(), re);
    for (auto it{begin}; it != std::sregex_iterator(); ++it) {
      if (it->str() == "do()") {
        multiply = true;
        continue;
      }
      if (it->str() == "don't()") {
        multiply = false;
        continue;
      }
      if (multiply) {
        acc += Multiply(it->str());
      }
    }
    return acc;
  });
}

}  // namespace aoc::aoc2024
