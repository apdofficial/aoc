#pragma once

template <typename VALUE_TYPE_>
struct XY {
  VALUE_TYPE_ x{};
  VALUE_TYPE_ y{};
};

template <typename VALUE_TYPE_>
struct Point : public XY<VALUE_TYPE_> {
  auto friend operator==(Point const& lhs, Point const& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }

  auto friend operator!=(Point const& lhs, Point const& rhs) {
    return !(lhs == rhs);
  }

  auto friend operator+(Point const& lhs, Point const& rhs) -> Point {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
  }

  auto friend operator-(Point const& lhs, Point const& rhs) -> Point {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
  }
};
