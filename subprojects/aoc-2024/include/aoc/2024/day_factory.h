#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

#include <memory>

namespace aoc::aoc2024 {

std::unique_ptr<aoc::IDay> DayFactory(unsigned day, aoc::IPuzzleReader* reader);

}  // namespace aoc::aoc2022
