#include <aoc/2022/day07.h>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <span>
#include <sstream>
#include <string>

namespace {

auto CalcualteDirSizes(std::span<std::string> input_cmds)
    -> std::map<std::string, int> {
  std::map<std::string, int> dir_sizes{};
  std::vector<std::string> current{};
  for (auto const& cmd : input_cmds) {
    if (cmd.starts_with("$ ls") || cmd.starts_with("dir")) {
      continue;
    }
    if (cmd.starts_with("$ cd")) {
      auto dest = cmd.substr(5, cmd.size());
      if (dest == "..") {
        current.pop_back();
      } else {
        current.push_back(dest);
      }
    } else {
      auto size = std::stoi(cmd.substr(0, cmd.find(" ")));
      auto tmp = current;
      const char* const delim = "/";
      while (!tmp.empty()) {
        std::ostringstream key;
        std::copy(tmp.begin(), tmp.end(),
                  std::ostream_iterator<std::string>(key, delim));
        auto val = dir_sizes[key.str()];
        dir_sizes[key.str()] = val == 0 ? size : val + size;
        tmp.pop_back();
      }
    }
  }
  return dir_sizes;
}

}  // namespace

namespace aoc::aoc2022 {

Day7::Day7(IPuzzleReader::Lines const& lines) : lines_{lines} {}

auto Day7::SolvePart1() -> Puzzle::Part1 {
  auto dir_sizes = CalcualteDirSizes(lines_);
  int sum{};
  for (auto const& [k, v] : dir_sizes) {
    if (v <= 100000) {
      sum += v;
    }
  }
  return sum;
}

auto Day7::SolvePart2() -> Puzzle::Part2 {
  auto dir_sizes = CalcualteDirSizes(lines_);
  int minsize = dir_sizes["//"] - 40000000;
  std::set<int> candidates{};
  for (auto const& [k, v] : dir_sizes) {
    if (v >= minsize) {
      candidates.insert(v);
    }
  }
  return *candidates.begin();
}

};  // namespace aoc::aoc2022
