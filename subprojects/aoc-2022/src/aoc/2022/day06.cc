#include <aoc/2022/day06.h>
#include <bitset>
#include <limits>
#include <string_view>

namespace {

auto StartOfMessageMarker(std::string_view line, size_t match_count) -> int {
  std::bitset<std::numeric_limits<short>::max()> bitset;
  for (int i{0}; i < line.size(); ++i) {
    bitset ^= 1 << (line[i] - 'a');
    if (i >= match_count) {
      // start switchong off chars to the left of the window
      bitset ^= 1 << (line[i - match_count] - 'a');
      if (bitset.count() == match_count) {
        return i + 1;
      }
    }
  }
  return 0;
}

}  // namespace

namespace aoc::aoc2022 {

Day6::Day6(PuzzleReader::Line const& line) : line_{line} {}

auto Day6::SolvePart1() -> Puzzle::Part1 {
  return StartOfMessageMarker(line_, 4);
}

auto Day6::SolvePart2() -> Puzzle::Part2 {
  return StartOfMessageMarker(line_, 14);
}

};  // namespace aoc::aoc2022
