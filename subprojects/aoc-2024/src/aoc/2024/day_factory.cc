#include <aoc/2024/day01.h>
#include <aoc/2024/day02.h>
#include <aoc/2024/day_factory.h>

#include <format>

namespace aoc::aoc2024 {

std::unique_ptr<aoc::IDay> DayFactory(unsigned day, aoc::IPuzzleReader* reader) {
  using namespace aoc::aoc2024;
  switch (day) {
    case 1:
      return std::make_unique<Day1>(reader->ReadLines());
    case 2:
      return std::make_unique<Day2>(reader->ReadLines());
    default:
      throw std::invalid_argument(std::format("Unsupported day {}", day));
  }
}

}  // namespace aoc::aoc2022
