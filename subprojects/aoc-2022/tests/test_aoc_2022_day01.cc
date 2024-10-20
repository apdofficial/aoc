#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day01.hh>
#include <aoc/common/file_puzzle_reader.hh>

std::vector<std::string> const kShortInput{
    "1000", "2000", "3000", "",     "4000", "", "5000",
    "6000", "",     "7000", "8000", "9000", "", "10000"};

constexpr std::string_view kDataPath = "../data/2022/day01.txt";

TEST_CASE("Day 01, part 1", "[2022-01-01]") {
  aoc::aoc2022::Day1 day1{kShortInput};
  REQUIRE(day1.SolvePart1() == 24000);
}

TEST_CASE("Day 01, part 2", "[2022-01-02]") {
  aoc::aoc2022::Day1 day1{kShortInput};
  REQUIRE(day1.SolvePart2() == 45000);
}

TEST_CASE("Day 01, file", "[2022-01]") {
  aoc::FilePuzzleReader file(kDataPath);
  aoc::aoc2022::Day1 day1{file};
  REQUIRE(day1.SolvePart1() == 69693);
  REQUIRE(day1.SolvePart2() == 200945);
}
