#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day02.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
IPuzzleReader::Lines const kShortInput{
  "A Y",
  "B X", 
  "C Z",
};
// clang-format on

TEST_CASE("Day 02, part 1", "[Y2022-D02-P01]") {
  aoc2022::Day2 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 15);
}

TEST_CASE("Day 02, part 2", "[Y2022-D02-P02]") {
  aoc2022::Day2 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 12);
}
