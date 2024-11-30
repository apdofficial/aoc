#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <filesystem>

namespace aoc {

PuzzleFileReader::PuzzleFileReader(std::filesystem::path input)
    : file_(std::ifstream(input)) {
  if (!file_.is_open()) {
    throw std::runtime_error("Failed to open FilePuzzleReader.");
  }
}

PuzzleFileReader::~PuzzleFileReader() {
  file_.close();
}

auto PuzzleFileReader::ReadLines() -> Lines {
  Lines lines;
  Line line;
  while (getline(file_, line)) {
    lines.emplace_back(line);
  }
  return lines;
}

}  // namespace aoc
