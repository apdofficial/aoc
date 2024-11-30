#include <aoc/common/cli/parser.h>

#include <fmt/format.h>
#include <boost/program_options.hpp>

#include <cstdlib>
#include <functional>
#include <iostream>
#include <stdexcept>

namespace aoc {

CliArguments ParseCli(int argc,
                      char* argv[],
                      std::ostream& os,
                      std::function<void()> print_version) {
  namespace po = boost::program_options;
  po::options_description desc("aoc");
  desc.add_options()("help,h", "show help");
  desc.add_options()("version,v", "show version");
  desc.add_options()("day,d", po::value<unsigned>(), "day to solve");
  desc.add_options()("input-file", po::value<std::string>(),
                     "puzzle input file");
  po::variables_map vm{};
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);
  if (vm.count("help")) {
    desc.print(os);
    std::exit(0);
  }
  if (vm.count("version")) {
    print_version();
    std::exit(0);
  }
  if (!vm.count("day")) {
    throw std::invalid_argument(
        "Error: No day has been selected. Use --help for usage.");
  }
  if (!vm.count("input-file")) {
    throw std::invalid_argument(
        "Error: No input has been provided. Use --help for usage.");
  }
  return {vm["day"].as<unsigned>(),
          aoc::CliArguments::InputFilePath{vm["input-file"].as<std::string>()}};
};

}  // namespace aoc