#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day02.hh>
#include <aoc/common/file_puzzle_reader.hh>

std::vector<std::pair<char, char>> const kShortInput{{'A', 'Y'},
                                                     {'B', 'X'},
                                                     {'C', 'Z'}};

TEST_CASE("Day 02, part 1", "[Y2022-D02-P01]") {
  aoc::aoc2022::Day2 day2{kShortInput};
  REQUIRE(day2.SolvePart1() == 15);
}

TEST_CASE("Day 02, part 2", "[Y2022-D02-P02]") {
  aoc::aoc2022::Day2 day2{kShortInput};
  REQUIRE(day2.SolvePart2() == 12);
}
