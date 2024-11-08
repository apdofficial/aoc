#include <aoc/common/range/range.h>

namespace aoc {

auto Range::size() const -> long {
  return end - start;
}

auto Range::contains(long const value) const -> bool {
  return start <= value && value < end;
}

auto Range::is_sub_range(Range const& rhs) const -> bool {
  return start >= rhs.start && end <= rhs.end;
}

auto Range::intersects(Range const& rhs) const -> bool {
  return start <= rhs.start && rhs.start <= end;
}

auto Range::is_adjacent(Range const& rhs) const -> bool {
  return start == rhs.end || end == rhs.start;
}

auto merge(Range const& lhs, Range const& rhs) -> std::optional<Range> {
  if ((lhs.intersects(rhs) || lhs.is_adjacent(rhs)) && lhs != rhs) {
    return Range{std::min(lhs.start, rhs.start), std::max(lhs.end, rhs.end)};
  }
  return std::nullopt;
}

}  // namespace aoc
