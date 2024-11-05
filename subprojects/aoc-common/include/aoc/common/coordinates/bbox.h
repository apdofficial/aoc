#pragma once

#include <aoc/common/coordinates/point.h>

struct BBox2D {
  XY<double> offset{};
  double width{};
  double height{};
};
