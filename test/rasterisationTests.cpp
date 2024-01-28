#include <gtest/gtest.h>

#include "rasterisation.h"

using namespace Rasterisation;

TEST(rasterisationTests, equalPoints_calculateLine_returnsEmpty)
{
   Point a{0, 0};
   Point b{0, 0};

   const auto points = calculateLine(a, b);

   EXPECT_TRUE(points.empty());
}