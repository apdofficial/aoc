#include <aoc/2022/day01.h>
#include <aoc/2022/day02.h>
#include <aoc/2022/day03.h>
#include <aoc/2022/day04.h>
#include <aoc/2022/day05.h>
#include <aoc/2022/day06.h>
#include <aoc/2022/day07.h>
#include <aoc/2022/day_factory.h>

#include <format>

namespace aoc::aoc2022 {

std::unique_ptr<aoc::IDay> DayFactory(unsigned day, aoc::PuzzleReader& reader) {
  using namespace aoc::aoc2022;
  switch (day) {
    case 1:
      return std::make_unique<Day1>(reader.ReadLines());
    case 2:
      return std::make_unique<Day2>(reader.ReadLines());
    case 3:
      return std::make_unique<Day3>(reader.ReadLines());
    case 4:
      return std::make_unique<Day4>(reader.ReadLines());
    case 5:
      return std::make_unique<Day5>(reader.ReadLines());
    case 6:
      return std::make_unique<Day6>(reader.ReadLines().front());
    case 7:
      return std::make_unique<Day7>(reader.ReadLines());
    default:
      throw std::invalid_argument(std::format("Unsupported day {}", day));
  }
}

}  // namespace aoc::aoc2022
