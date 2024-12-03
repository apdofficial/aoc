#include <catch2/catch_test_macros.hpp>

#include <aoc/2024/day03.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
IPuzzleReader::Lines const kShortInput1{
  "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"
};

IPuzzleReader::Lines const kShortInput2{
  "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))"
};
// clang-format off 

TEST_CASE("Day 03, part 1", "[2024-03-01]") {
  aoc2024::Day3 day{kShortInput1};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 161);
}

TEST_CASE("Day 03, part 2", "[2024-03-02]") {
  aoc2024::Day3 day{kShortInput2};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 48);
}
