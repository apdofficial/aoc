#include <aoc/2022/day03.hh>
#include <aoc/common/puzzle_reader.hh>

#include <algorithm>
#include <cctype>
#include <numeric>
#include <string>

namespace {

int CalculatePriority(char c) {
  return std::isupper(c) ? c - 'A' + 27 : c - 'a' + 1;
}

std::string FindMatches(std::string const& s1, std::string const& s2) {
  std::string matches;
  for (auto const& item : s1) {
    auto const found = std::find(matches.begin(), matches.end(), item);
    if (s2.find(item) != std::string::npos && found == matches.end()) {
      matches.push_back(item);
    }
  }
  return matches;
}

}  // namespace

namespace aoc::aoc2022 {

Day3::Day3(PuzzleReader::Lines const& lines) : lines_(lines) {}

int Day3::SolvePart1() {
  auto acc_rucksack = [](auto acc, std::string const& rucksack) {
    auto const comp1 = rucksack.substr(0, rucksack.size() / 2);
    auto const comp2 = rucksack.substr(rucksack.size() / 2, rucksack.size());
    for (auto const match : FindMatches(comp1, comp2)) {
      acc += CalculatePriority(match);
    }
    return acc;
  };
  return std::accumulate(lines_.begin(), lines_.end(), 0, acc_rucksack);
}

int Day3::SolvePart2() {
  int acc{};
  for (size_t i{}; i + 3 <= lines_.size(); i += 3) {
    auto const matches =
        FindMatches(FindMatches(lines_[i], lines_[i + 1]), lines_[i + 2]);
    for (auto const match : matches) {
      acc += CalculatePriority(match);
    };
  }
  return acc;
}

};  // namespace aoc::aoc2022
