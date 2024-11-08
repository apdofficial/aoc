#pragma once

#include <aoc/common/puzzle/puzzle_reader.h>

#include <fstream>
#include <string_view>

namespace aoc {

struct PuzzleFileReader : public PuzzleReader {
  PuzzleFileReader(std::string_view file_path);

  ~PuzzleFileReader() override;

  PuzzleFileReader() = delete;

  PuzzleFileReader(PuzzleFileReader const&) = delete;
  PuzzleFileReader(PuzzleFileReader&&) noexcept = default;

  PuzzleFileReader operator=(PuzzleFileReader const&) = delete;
  PuzzleFileReader& operator=(PuzzleFileReader&&) noexcept = default;

  auto ReadLines() -> Lines override;

 private:
  std::ifstream file_{};
};

}  // namespace aoc
