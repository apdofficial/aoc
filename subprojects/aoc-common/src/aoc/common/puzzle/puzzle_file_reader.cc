#include <aoc/common/puzzle/puzzle_file_reader.h>

namespace aoc {

PuzzleFileReader::PuzzleFileReader(std::string_view file_path)
    : file_(std::ifstream(file_path.data())) {
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
