#include "rasterisation.h"

using namespace std;

namespace Rasterisation
{
vector<Point> calculateLine(Point p0, Point p1)
{
   vector<Point> points;

   if (p0.x == p1.x && p0.y == p1.y) {
      return points;
   }

   // Slope > 1
   const auto slopeIsSteep = abs(p1.y - p0.y) > abs(p1.x - p0.x);
   if (slopeIsSteep) {
      swap(p0.x, p0.y);
      swap(p1.x, p1.y);
   }

   // Reverse direction
   if (p0.x > p1.x) {
      swap(p0.x, p1.x);
      swap(p0.y, p1.y);
   }

   const auto deltaX = p1.x - p0.x;
   auto deltaY = p1.y - p0.y;
   auto yIncrement = 1;

   // Negative slope
   if (p1.y < p0.y) {
      yIncrement = -1;
      deltaY = -deltaY;
   }

   auto decisionError = 2 * deltaY - deltaX;

   auto y = p0.y;
   for (int x = p0.x; x <= p1.x; x++) {
      points.push_back(slopeIsSteep ? Point{y, x} : Point{x, y});
      if (decisionError > 0) {
         y += yIncrement;
         decisionError -= 2 * deltaX;
      }
      decisionError += 2 * deltaY;
   }

   return points;
}
} // namespace Rasterisation