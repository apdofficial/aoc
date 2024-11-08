#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day03.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
PuzzleFileReader::Lines const kShortInput{
  "vJrwpWtwJgWrhcsFMMfFFhFp", 
  "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
  "PmmdzqPrVvPwwTWBwg",       
  "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
  "ttgJtRGJQctTZtZT",        
  "CrZsJsPPZsGzwwsLwLmpwMDw",
};
// clnag format on

TEST_CASE("Day 03, part 1", "[Y2022-D03-P01]") {
  aoc2022::Day3 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 157);
}

TEST_CASE("Day 03, part 2", "[Y2022-D03-P02]") {
  aoc2022::Day3 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 70);
}
