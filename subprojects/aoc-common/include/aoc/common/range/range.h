#pragma once

#include <iostream>
#include <optional>

namespace aoc {

/**
 * @brief Half right open interval [start, end)
 */
class Range {
 public:
  auto friend operator==(Range const& lhs, Range const& rhs) {
    return rhs.start == lhs.start && rhs.end == lhs.end;
  }

  auto friend operator!=(Range const& lhs, Range const& rhs) {
    return !(rhs == lhs);
  }

  auto friend operator<=>(Range const& lhs, Range const& rhs) {
    if (lhs.start < rhs.start)
      return std::strong_ordering::less;
    if (lhs.start > rhs.start)
      return std::strong_ordering::greater;
    if (lhs.end < rhs.end)
      return std::strong_ordering::less;
    if (lhs.end > rhs.end)
      return std::strong_ordering::greater;
    return std::strong_ordering::equal;
  }
  auto friend operator>>(std::istream& is, Range& other) -> std::istream& {
    char delimiter{};
    is >> other.start >> delimiter >> other.end;
    return is;
  }

  [[nodiscard]] auto size() const -> long;

  [[nodiscard]] auto contains(long const value) const -> bool;

  [[nodiscard]] auto is_sub_range(Range const& rhs) const -> bool;

  [[nodiscard]] auto intersects(Range const& rhs) const -> bool;

  [[nodiscard]] auto is_adjacent(Range const& rhs) const -> bool;

  long start{};
  long end{};
};

auto merge(Range const&, Range const&) -> std::optional<Range>;

}  // namespace aoc
