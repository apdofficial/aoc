#include <aoc/2022/day_factory.h>

#include <aoc/common/cli/parser.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader.h>
#include <aoc/common/puzzle/puzzle_reader_factory.h>

#include <fmt/format.h>

#include <variant>
#include <iostream>

int main(int argc, char* argv[]) {
  auto arguments = aoc::ParseCli(argc, argv, std::cout, [](){fmt::println(PROJECT_VERSION);});
  auto reader = aoc::PuzzleReaderFactory(arguments);
  auto day = aoc::aoc2022::DayFactory(arguments.day, reader.get());

  fmt::println("Day: {:02}\n", arguments.day);
  aoc::Puzzle puzzle{day->SolvePart1(), day->SolvePart2()};

  std::visit([](const auto& k) { fmt::println("Puzzle 1: {}", k); },
             puzzle.part1);
  std::visit([](const auto& k) { fmt::println("Puzzle 2: {}", k); },
             puzzle.part2);
  return 0;
}
