#include <catch2/catch_test_macros.hpp>

#include <aoc/2024/day01.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
IPuzzleReader::Lines const kShortInput{

};
// clang-format off 

TEST_CASE("Day 01, part 1", "[2024-01-01]") {
  aoc2024::Day1 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 0);
}

TEST_CASE("Day 01, part 2", "[2024-01-02]") {
  aoc2024::Day1 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 0);
}