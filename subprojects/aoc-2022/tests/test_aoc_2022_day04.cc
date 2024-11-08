#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day04.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
aoc::PuzzleFileReader::Lines const kShortInput{
    "2-4,6-8",
    "2-3,4-5", 
    "5-7,7-9", 
    "2-8,3-7", 
    "6-6,4-6", 
    "2-6,4-8",
};
// clnag format on

TEST_CASE("Day 04, part 1", "[Y2022-D04-P01]") {
  aoc::aoc2022::Day4 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 2);
}

TEST_CASE("Day 04, part 2", "[Y2022-D04-P02]") {
  aoc::aoc2022::Day4 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 4);
}
