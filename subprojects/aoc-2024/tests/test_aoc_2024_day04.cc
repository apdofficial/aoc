#include <catch2/catch_test_macros.hpp>

#include <aoc/2024/day04.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
IPuzzleReader::Lines const kShortInput{
    "MMMSXXMASM",
    "MSAMXMSMSA",
    "AMXSXMAAMM",
    "MSAMASMSMX",
    "XMASAMXAMM",
    "XXAMMXXAMA",
    "SMSMSASXSS",
    "SAXAMASAAA",
    "MAMMMXMMMM",
    "MXMXAXMASX",
};
// clang-format off 

TEST_CASE("Day 04, part 1", "[2024-04-01]") {
  aoc2024::Day4 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 18);
}

TEST_CASE("Day 04, part 2", "[2024-04-02]") {
  aoc2024::Day4 day{kShortInput};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 9);
}
