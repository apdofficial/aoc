#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

#include <aoc/2022/day07.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>

using namespace aoc;

// clang-format off
std::vector<std::string> const kShortInputPart{
    "$ cd /",
    "$ ls",
    "dir a",
    "14848514 b.txt",
    "8504156 c.dat",
    "dir d",
    "$ cd a",
    "$ ls",
    "dir e",
    "29116 f",
    "2557 g",
    "62596 h.lst",
    "$ cd e",
    "$ ls",
    "584 i",
    "$ cd ..",
    "$ cd ..",
    "$ cd d",
    "$ ls",
    "4060174 j",
    "8033020 d.log",
    "5626152 d.ext",
    "7214296 k",
};
// clang-format on

TEST_CASE("Day 07, part 1", "[Y2022-D07-P01]") {
  aoc::aoc2022::Day7 day{kShortInputPart};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart1()) == 95437);
}

TEST_CASE("Day 07, part 2", "[Y2022-D07-P02]") {
  aoc::aoc2022::Day7 day{kShortInputPart};
  REQUIRE(std::get<Puzzle::NumberType>(day.SolvePart2()) == 24933642);
}
