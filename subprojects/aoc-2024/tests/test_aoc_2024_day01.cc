#include <catch2/catch_test_macros.hpp>

#include <aoc/2024/day01.hh>
#include <aoc/common/file_puzzle_reader.hh>

aoc::FilePuzzleReader::Lines const kShortInput{""};

TEST_CASE("Day 01, part 1 test") {
  aoc::aoc2024::Day1 day1{kShortInput};
  if (day1.SolvePart1() == -1) {
    FAIL("day1.SolvePart1() is not implemented.");
  }
}

TEST_CASE("Day 01, part 2 test") {
  aoc::aoc2024::Day1 day1{kShortInput};
  if (day1.SolvePart2() == -1) {
    FAIL("day1.SolvePart2() is not implemented.");
  }
}
