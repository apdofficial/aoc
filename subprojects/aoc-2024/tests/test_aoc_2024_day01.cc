#include <catch2/catch_test_macros.hpp>

#include <aoc/2024/day01.hh>
#include <aoc/common/file_puzzle_reader.hh>

std::vector<std::string> const kShortInput{};

constexpr std::string_view kDataPath = "../data/2024/day01.txt";

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

TEST_CASE("Day 01, file") {
  aoc::FilePuzzleReader file(kDataPath);
  aoc::aoc2024::Day1 day1{file};
  if (day1.SolvePart1() == -1) {
    FAIL("day1.SolvePart1() is not implemented.");
  }
  if (day1.SolvePart2() == -1) {
    FAIL("day1.SolvePart2() is not implemented.");
  }
}
