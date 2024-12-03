#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day01.hh>
#include <aoc/common/file_puzzle_reader.hh>
#include <aoc/common/puzzle_reader.hh>

aoc::PuzzleReader::Lines const kShortInput{
    "1000", "2000", "3000", "",     "4000", "", "5000",
    "6000", "",     "7000", "8000", "9000", "", "10000"};

TEST_CASE("Day 01, part 1", "[2022-01-01]") {
  aoc::aoc2022::Day1 day1{kShortInput};
  REQUIRE(day1.SolvePart1() == 24000);
}

TEST_CASE("Day 01, part 2", "[2022-01-02]") {
  aoc::aoc2022::Day1 day1{kShortInput};
  REQUIRE(day1.SolvePart2() == 45000);
}
