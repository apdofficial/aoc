#pragma once

#include <aoc/common/day.h>
#include <aoc/common/puzzle/puzzle_reader.h>
#include <string>

namespace aoc::aoc2022 {

class Day7 : public IDay {
 public:
  enum class Command { cd, ls, invalid };

  class Inode {
   public:
    Inode(std::string name, size_t size)
        : name_{std::move(name)}, size_{size} {};
    auto size() { return size_; }
    auto name() { return name_; }

   private:
    std::string name_{};
    size_t size_{};
  };

  class File : public Inode {
   public:
    File(std::string const& name, size_t size) : Inode(name, size){};
  };

  class Directory : public Inode {
   public:
    Directory(std::string const& name, size_t size) : Inode(name, size){};
  };

  Day7(PuzzleReader::Lines const&);

  [[nodiscard]] auto SolvePart1() -> Puzzle::Part1 override;
  [[nodiscard]] auto SolvePart2() -> Puzzle::Part2 override;

 private:
  PuzzleReader::Lines lines_{};
};

}  // namespace aoc::aoc2022
