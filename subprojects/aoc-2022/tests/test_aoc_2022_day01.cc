#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day01.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
PuzzleReader::Lines const kShortInput{
  "1000", "2000", "3000", "",     
  "4000", "",     
  "5000", "6000", "",     
  "7000", "8000", "9000", "",    
  "10000"
};
// clang-format off 

TEST_CASE("Day 01, part 1", "[2022-01-01]") {
  aoc2022::Day1 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 24000);
}

TEST_CASE("Day 01, part 2", "[2022-01-02]") {
  aoc2022::Day1 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 45000);
}
