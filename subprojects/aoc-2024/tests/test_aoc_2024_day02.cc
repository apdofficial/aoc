#include <catch2/catch_test_macros.hpp>

#include <aoc/2024/day02.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
IPuzzleReader::Lines const kShortInput{
    "7 6 4 2 1",
    "1 2 7 8 9",
    "9 7 6 2 1",
    "1 3 2 4 5",
    "8 6 4 4 1",
    "1 3 6 7 9",
};
// clang-format off 

TEST_CASE("Day 02, part 1", "[2024-02-01]") {
  aoc2024::Day2 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 2);
}

TEST_CASE("Day 02, part 2", "[2024-02-02]") {
  aoc2024::Day2 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 4);
}
