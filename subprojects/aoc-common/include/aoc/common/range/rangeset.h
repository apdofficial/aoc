#pragma once

#include <aoc/common/range/range.h>

#include <set>

namespace aoc {

class RangeSet {
 public:
  void insert(Range const& new_range);

  void erase(Range const& range);

  [[nodiscard]] auto ranges() const -> std::set<Range> const&;

  [[nodiscard]] auto count_values() const -> size_t;
  [[nodiscard]] auto contains(long const col) const -> bool;

 private:
  auto merge(Range const& new_range) -> bool;

  std::set<Range> ranges_{};
};

}  // namespace aoc
