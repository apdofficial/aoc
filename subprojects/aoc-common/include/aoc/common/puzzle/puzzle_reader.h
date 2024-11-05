#pragma once

#include <string>
#include <vector>

namespace aoc {

struct PuzzleReader {
  using Line = std::string;
  using Lines = std::vector<Line>;

  virtual ~PuzzleReader() = default;

  virtual auto ReadLines() -> Lines = 0;
};

}  // namespace aoc
