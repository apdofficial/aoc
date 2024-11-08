#include <aoc/2022/day05.h>

#include <iterator>
#include <regex>
#include <string>
#include <vector>

namespace {

auto Parse(std::string const& line) -> aoc::aoc2022::Day5::Command {
  std::regex re{"[0-9]+"};
  auto begin = std::sregex_iterator(line.begin(), line.end(), re);
  std::vector<int> matches;
  for (auto it{begin}; it != std::sregex_iterator(); ++it) {
    matches.push_back(std::stoi((*it).str()));
  }
  return {matches[0] - 1, matches[1] - 1, matches[2] - 1};
}

auto Parse(std::string const& line, aoc::aoc2022::Day5::Stacks& stacks) {
  std::regex re{"[A-Z]"};
  auto begin = std::sregex_iterator(line.begin(), line.end(), re);
  for (auto it{begin}; it != std::sregex_iterator(); ++it) {
    size_t const i = (it->position() < 4 ? 0 : it->position() / 4);
    while (stacks.size() <= i) {
      stacks.emplace_back();
    }
    stacks.at(i).push_back((*it).str().front());
  }
}

}  // namespace

namespace aoc::aoc2022 {

Day5::Day5(PuzzleReader::Lines const& lines) {
  for (auto const& line : lines) {
    if (line.starts_with("move")) {
      commands_.emplace_back(Parse(line));
      continue;
    }
    Parse(line, stacks_);
  }
  for (auto& stack : stacks_) {
    std::reverse(stack.begin(), stack.end());
  }
}

auto Day5::SolvePart1() -> Puzzle::Part1 {
  auto stacks = stacks_;
  for (auto const& [crate, src, dst] : commands_) {
    for (size_t i = 0; i < crate + 1; i++) {
      stacks[dst].push_back(stacks[src].back());
      stacks[src].pop_back();
    }
  }
  std::string res;
  for (auto const& stack : stacks) {
    res += stack.back();
  }
  return res;
}

auto Day5::SolvePart2() -> Puzzle::Part2 {
  auto stacks = stacks_;
  for (auto const& [crate, src, dst] : commands_) {
    const auto it = std::prev(stacks[src].end(), crate + 1);
    std::move(it, stacks[src].end(), std::back_inserter(stacks[dst]));
    for (size_t i = 0; i < crate + 1; i++)
      stacks[src].pop_back();
  }
  std::string res;
  for (auto const& stack : stacks) {
    res += stack.back();
  }
  return res;
}

};  // namespace aoc::aoc2022
