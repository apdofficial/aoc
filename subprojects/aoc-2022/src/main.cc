#include <aoc/2022/day_factory.h>
#include <aoc/common/puzzle/puzzle.h>
#include <aoc/common/puzzle/puzzle_file_reader.h>

#include <fmt/format.h>
#include <boost/program_options.hpp>

#include <iostream>
#include <string>
#include <variant>

int main(int argc, char* argv[]) {
  namespace po = boost::program_options;
  try {
    po::options_description desc("aoc2022");
    desc.add_options()("help,h", "show help");
    desc.add_options()("version,v", "show version");
    desc.add_options()("day,d", po::value<unsigned>(), "day to solve");
    desc.add_options()("input-file", po::value<std::string>(),
                       "puzzle input file");
    po::variables_map vm{};
    po::store(po::parse_command_line(argc, argv, desc), vm);
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
                   "Error: No day has been selected. Use --help for usage.");
      return 1;
    }
    if (!vm.count("input-file")) {
      fmt::println(stderr,
                   "Error: No input has been provided. Use --help for usage.");
      return 1;
    }

    auto const day_nr{vm["day"].as<unsigned>()};
    fmt::println("Day: {:02}\n", day_nr);

    aoc::PuzzleFileReader reader{vm["input-file"].as<std::string>()};
    auto day{aoc::aoc2022::DayFactory(day_nr, reader)};
    aoc::Puzzle puzzle{day->SolvePart1(), day->SolvePart2()};

    std::visit([](const auto& k) { fmt::println("Puzzle 1: {}", k); },
               puzzle.part1);
    std::visit([](const auto& k) { fmt::println("Puzzle 2: {}", k); },
               puzzle.part2);

  } catch (std::exception& e) {
    fmt::println(stderr, "Error: {}", e.what());
    return 1;
  }
  return 0;
}
