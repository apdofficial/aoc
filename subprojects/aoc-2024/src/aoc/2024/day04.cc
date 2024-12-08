#include <aoc/2024/day04.h>

#include <array>
#include <string>

namespace {

std::array<std::pair<int, int>, 8> const kDirections = {
    {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};

}  // namespace

namespace aoc::aoc2024 {

Day4::Day4(IPuzzleReader::Lines const& lines) : lines_{lines} {}

auto Day4::SolvePart1() -> Puzzle::Part1 {
  int count{};
  size_t m = lines_.size();
  std::string const target{"XMAS"};
  for (int i{}; i < m; ++i) {
    size_t n = lines_[i].size();
    for (int j{}; j < n; ++j) {
      if (lines_[i][j] == 'X') {
        for (auto [dx, dy] : kDirections) {
          int y = i;
          int x = j;
          for (int t = 1; t <= target.size() - 1; ++t) {
            x += dx;
            y += dy;
            if (x >= 0 && x < m && y >= 0 && y < n &&
                lines_[y][x] == target[t]) {
              if (t == 3) {
                count++;
              }
            } else {
              break;
            }
          }
        }
      }
    }
  }
  return count;
}

auto Day4::SolvePart2() -> Puzzle::Part2 {
  int count{};
  for (int i{}; i < lines_.size() - 2; ++i) {
    for (int j{}; j < lines_[i].size() - 2; ++j) {
      std::string diag1{};
      diag1 += lines_[i][j];
      diag1 += lines_[i + 1][j + 1];
      diag1 += lines_[i + 2][j + 2];

      std::string diag2{};
      diag2 += lines_[i][j + 2];
      diag2 += lines_[i + 1][j + 1];
      diag2 += lines_[i + 2][j];

      if ((diag1 == "MAS" || diag1 == "SAM") &&
          (diag2 == "MAS" || diag2 == "SAM")) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace aoc::aoc2024
