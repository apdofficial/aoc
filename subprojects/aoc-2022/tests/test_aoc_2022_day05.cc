#include <catch2/catch_test_macros.hpp>

#include <aoc/2022/day05.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
aoc::PuzzleFileReader::Lines const kShortInput{
    "    [D]           ",
    "[N] [C]           ",    
    "[Z] [M] [P]       ",
    " 1   2   3        ",
    "                  ",
    "move 1 from 2 to 1",
    "move 3 from 1 to 3",
    "move 2 from 2 to 1",
    "move 1 from 1 to 2",
};
// clang-format on

TEST_CASE("Day 04, part 1", "[Y2022-D04-P01]") {
  aoc::aoc2022::Day5 day{kShortInput};
  REQUIRE(std::get<Puzzle::TextType>(day.SolvePart1()) == "CMZ");
}

TEST_CASE("Day 04, part 2", "[Y2022-D04-P02]") {
  aoc::aoc2022::Day5 day{kShortInput};
  REQUIRE(std::get<Puzzle::TextType>(day.SolvePart2()) == "MCD");
}
