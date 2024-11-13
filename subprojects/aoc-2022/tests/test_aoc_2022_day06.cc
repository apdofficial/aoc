#include <catch2/catch_test_macros.hpp>
#include <vector>

#include <aoc/2022/day06.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;
using Line = aoc::PuzzleFileReader::Line;
using Answer = int;

// clang-format off
std::vector<std::pair<Line, Answer>> const kShortInputPart1{
    {"bvwbjplbgvbhsrlpgdmjqwftvncz",      5},
    {"nppdvjthqldpwncqszvftbrmjlhg",      6},    
    {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 10},
    {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw",  11},
};

std::vector<std::pair<Line, Answer>> const kShortInputPart2{
    {"mjqjpqmgbljsphdztnvjfqwrcgsmlb",    19},
    {"bvwbjplbgvbhsrlpgdmjqwftvncz",      23},    
    {"nppdvjthqldpwncqszvftbrmjlhg",      23},
    {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 29},
    {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw",  26},
};
// clang-format on

TEST_CASE("Day 06, part 1", "[Y2022-D06-P01]") {
  for (auto const& [line, answer] : kShortInputPart1) {
    aoc::aoc2022::Day6 day{{line}};
    REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == answer);
  }
}

TEST_CASE("Day 06, part 2", "[Y2022-D06-P02]") {
  for (auto const& [line, answer] : kShortInputPart2) {
    aoc::aoc2022::Day6 day{{line}};
    REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == answer);
  }
}
