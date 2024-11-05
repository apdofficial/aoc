#include <aoc/common/range/rangeset.h>

#include <algorithm>
#include <numeric>

namespace aoc {

void RangeSet::insert(Range const& new_range) {
  if (!merge(new_range)) {
    ranges_.insert(new_range);
  }
}

void RangeSet::erase(Range const& range) {
  ranges_.erase(range);
}

auto RangeSet::ranges() const -> std::set<Range> const& {
  return ranges_;
}

auto RangeSet::count_values() const -> size_t {
  return std::accumulate(ranges_.begin(), ranges_.end(), 0,
                         [](auto const& acc, auto const& range) {
                           return acc + std::abs(range.end - range.start);
                         });
}

auto RangeSet::contains(long const col) const -> bool {
  return std::ranges::any_of(
      ranges_, [col](auto const& range) { return range.contains(col); });
}

auto RangeSet::merge(Range const& new_range) -> bool {
  for (auto range : ranges_) {
    if (auto const merged_range = ::aoc::merge(range, new_range)) {
      ranges_.erase(range);
      ranges_.insert(*merged_range);
      merge(*merged_range);
      return true;
    }
  }
  return false;
}

}  // namespace aoc
