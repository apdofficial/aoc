#pragma once

#include <aoc/common/cli/cli_arguments.h>
#include <functional>

namespace aoc {

CliArguments ParseCli(int argc,
                      char* argv[],
                      std::ostream& os,
                      std::function<void()> print_version);

}