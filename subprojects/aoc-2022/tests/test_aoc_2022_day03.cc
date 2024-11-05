#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day03.hh>
#include <aoc/common/file_puzzle_reader.hh>

aoc::FilePuzzleReader::Lines const kShortInput{
    "vJrwpWtwJgWrhcsFMMfFFhFp", "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
    "PmmdzqPrVvPwwTWBwg",       "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
    "ttgJtRGJQctTZtZT",         "CrZsJsPPZsGzwwsLwLmpwMDw",
};

TEST_CASE("Day 03, part 1", "[Y2022-D03-P01]") {
  aoc::aoc2022::Day3 day{kShortInput};
  REQUIRE(day.SolvePart1() == 157);
}

TEST_CASE("Day 03, part 2", "[Y2022-D03-P02]") {
  aoc::aoc2022::Day3 day{kShortInput};
  REQUIRE(day.SolvePart2() == 70);
}
