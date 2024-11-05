#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>

#include <memory>

namespace aoc::aoc2022 {

std::unique_ptr<aoc::IDay> DayFactory(unsigned day, aoc::PuzzleReader& reader);

}  // namespace aoc::aoc2022
