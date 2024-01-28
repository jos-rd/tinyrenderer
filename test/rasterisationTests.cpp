#include <gtest/gtest.h>

#include "rasterisation.h"

using namespace std;
using namespace Rasterisation;

namespace
{
struct TestParams
{
   Point pointA;
   Point pointB;
   vector<Point> expectedPoints;
};

const vector<Point> resultSlopePositiveOne{
   Point{-2, -2}, Point{-1, -1}, Point{0, 0}, Point{1, 1}, Point{2, 2}};
const vector<Point> resultSlopeNegativeOne{
   Point{-2, 2}, Point{-1, 1}, Point{0, 0}, Point{1, -1}, Point{2, -2}};
const vector<Point> resultSlopeVertical{Point{2, -2}, Point{2, -1}, Point{2, 0},
                                        Point{2, 1}, Point{2, 2}};
const vector<Point> resultSlopeHorizontal{
   Point{-2, 2}, Point{-1, 2}, Point{0, 2}, Point{1, 2}, Point{2, 2}};

const vector<Point> resultNonSteepPositiveSlope{
   Point{0, 1}, Point{1, 1}, Point{2, 2}, Point{3, 2},
   Point{4, 3}, Point{5, 3}, Point{6, 4}};
const vector<Point> resultNonSteepNegativeSlope{
   Point{-6, 4}, Point{-5, 4}, Point{-4, 3}, Point{-3, 3},
   Point{-2, 2}, Point{-1, 2}, Point{0, 1}};
const vector<Point> resultSteepPositiveSlope{
   Point{1, 0}, Point{1, 1}, Point{2, 2}, Point{2, 3},
   Point{3, 4}, Point{3, 5}, Point{4, 6}};
const vector<Point> resultSteepNegativeSlope{
   Point{4, -6}, Point{4, -5}, Point{3, -4}, Point{3, -3},
   Point{2, -2}, Point{2, -1}, Point{1, 0}};
} // namespace

class BresenhamCalculateLineTestFixture
    : public ::testing::TestWithParam<TestParams>
{};

TEST_P(BresenhamCalculateLineTestFixture, calculateLine)
{
   auto [pointA, pointB, expectedPoints] = GetParam();

   const auto points = calculateLine(pointA, pointB);

   EXPECT_EQ(points, expectedPoints);
}

INSTANTIATE_TEST_CASE_P(
   CalculateLineTests, BresenhamCalculateLineTestFixture,
   ::testing::Values(
      TestParams(Point{0, 0}, Point{0, 0}, {}),
      TestParams(Point{-2, -2}, Point{2, 2}, resultSlopePositiveOne),
      TestParams(Point{-2, 2}, Point{2, -2}, resultSlopeNegativeOne),
      TestParams(Point{2, -2}, Point{2, 2}, resultSlopeVertical),
      TestParams(Point{-2, 2}, Point{2, 2}, resultSlopeHorizontal),
      TestParams(Point{0, 1}, Point{6, 4}, resultNonSteepPositiveSlope),
      TestParams(Point{0, 1}, Point{-6, 4}, resultNonSteepNegativeSlope),
      TestParams(Point{1, 0}, Point{4, 6}, resultSteepPositiveSlope),
      TestParams(Point{1, 0}, Point{4, -6}, resultSteepNegativeSlope),
      TestParams(Point{4, -6}, Point{1, 0}, resultSteepNegativeSlope)));