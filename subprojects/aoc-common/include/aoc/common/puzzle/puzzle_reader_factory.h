#pragma once

#include <aoc/common/cli/cli_arguments.h>
#include <aoc/common/puzzle/puzzle_reader.h>

#include <memory>

namespace aoc {

std::unique_ptr<aoc::IPuzzleReader> PuzzleReaderFactory(
    aoc::CliArguments const& arguments);

}  // namespace aoc
