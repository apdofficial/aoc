#include <aoc/2022/day03.hh>
#include <aoc/common/puzzle_reader.hh>
#include <cctype>
#include <numeric>
#include <string>

namespace aoc::aoc2022 {

Day3::Day3(PuzzleReader::Lines const& lines) : lines_(lines) {}

int Day3::SolvePart1() {
  auto acc_rucksack = [](auto acc, std::string const& rucksack) {
    auto const comp1 = rucksack.substr(0, rucksack.size() / 2);
    auto const comp2 = rucksack.substr(rucksack.size() / 2, rucksack.size());
    std::basic_string<char> seen;
    for (auto const& item : comp1) {
      if (comp2.find(item) != std::string::npos &&
          seen.find(item) == std::string::npos) {
        acc += std::isupper(item) ? item - 'A' + 27 : item - 'a' + 1;
        seen.push_back(item);
      }
    }
    return acc;
  };
  return std::accumulate(lines_.begin(), lines_.end(), 0, acc_rucksack);
}

int Day3::SolvePart2() {
  return -1;
}

};  // namespace aoc::aoc2022
