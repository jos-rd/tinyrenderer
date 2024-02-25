#include "rasterisation.h"
#include "tgaimage.h"

using namespace std;
using namespace Rasterisation;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

void plotPoints(TGAImage& image, const vector<Point>& points,
                const TGAColor& color)
{
   for (const auto& point : points) {
      image.set(point.x, point.y, color);
   }
}

void triangle(Point p0, Point p1, Point p2, TGAImage& image, TGAColor color)
{
   plotPoints(image, calculateLine(p0, p1), color);
   plotPoints(image, calculateLine(p1, p2), color);
   plotPoints(image, calculateLine(p2, p0), color);
}

int main(int argc, char** argv)
{
   TGAImage image(200, 200, TGAImage::RGB);

   triangle({10, 70}, {50, 160}, {70, 80}, image, red);
   triangle({180, 50}, {150, 1}, {70, 180}, image, white);
   triangle({180, 150}, {120, 160}, {130, 180}, image, green);


   // Place origin at the left bottom corner of the image
   image.flip_vertically();
   image.write_tga_file("output.tga");

   return 0;
}
