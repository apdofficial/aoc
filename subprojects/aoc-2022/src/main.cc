#include <aoc/2022/day01.hh>
#include <aoc/2022/day02.hh>
#include <aoc/2022/day03.hh>
#include <aoc/common/file_puzzle_reader.hh>
#include <aoc/common/puzzle_reader.hh>

#include <fmt/format.h>
#include <boost/program_options.hpp>

#include <iostream>
#include <optional>
#include <string>
#include <utility>

namespace {

std::pair<int, int> SolveDay(unsigned day, aoc::PuzzleReader& reader) {
  if (day == 1) {
    aoc::aoc2022::Day1 day_solver{reader.ReadLines()};
    return {day_solver.SolvePart1(), day_solver.SolvePart2()};
  } else if (day == 2) {
    aoc::aoc2022::Day2 day_solver{reader.ReadPairs()};
    return {day_solver.SolvePart1(), day_solver.SolvePart2()};
  } else if (day == 3) {
    aoc::aoc2022::Day3 day_solver{reader.ReadLines()};
    return {day_solver.SolvePart1(), day_solver.SolvePart2()};
  } else {
    throw std::invalid_argument(fmt::format("Unsupported day {}", day));
  }
}

}  // namespace

int main(int ac, char* av[]) {
  namespace po = boost::program_options;
  try {
    po::options_description desc("aoc2022");
    desc.add_options()("help,h", "show help");
    desc.add_options()("version,v", "show version");
    desc.add_options()("day,d", po::value<unsigned>(), "day to solve {1...2}");
    desc.add_options()("input-file", po::value<std::string>(),
                       "puzzle input file");
    po::variables_map vm{};
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);
    if (vm.count("help")) {
      desc.print(std::cout);
      return 0;
    }
    if (vm.count("version")) {
      fmt::println(PROJECT_VERSION);
      return 0;
    }
    if (!vm.count("day")) {
      fmt::println(stderr,
                   "Error: No day has been selected. Use --help for help.");
      return 1;
    }
    auto const day{vm["day"].as<unsigned>()};
    fmt::println("Day: {:02}\n", day);

    std::optional<std::pair<int, int>> solution{};
    if (vm.count("input-file")) {
      aoc::FilePuzzleReader reader{vm["input-file"].as<std::string>()};
      solution = SolveDay(day, reader);
    }

    if (!solution.has_value()) {
      fmt::println(stderr,
                   "Error: No input has been provided. Use --help for help.");
      return 1;
    }

    fmt::println("Puzzle 1: {:>20}", solution->first);
    fmt::println("Puzzle 2: {:>20}", solution->second);
  } catch (std::exception& e) {
    fmt::println(stderr, "Error: {}", e.what());
    return 1;
  }
  return 0;
}
