#pragma once

#include <vector>

namespace Rasterisation
{
struct Point
{
   int x;
   int y;

   auto operator<=>(const Point&) const = default;
};

std::vector<Point> calculateLine(Point& p0, Point& p1);
} // namespace Rasterisation