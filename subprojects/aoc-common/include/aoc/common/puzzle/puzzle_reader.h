#pragma once

#include <string>
#include <vector>

namespace aoc {

class IPuzzleReader {
 public:
  using Line = std::string;
  using Lines = std::vector<Line>;

  virtual ~IPuzzleReader() = default;

  virtual auto ReadLines() -> Lines = 0;
};

}  // namespace aoc
