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

int main(int argc, char** argv)
{
   TGAImage image(100, 100, TGAImage::RGB);

   // Draw line
   Point p0{0, 0};
   Point p1{100, 100};
   const auto points = calculateLine(p0, p1);
   plotPoints(image, points, blue);

   // Place origin at the left bottom corner of the image
   image.flip_vertically();
   image.write_tga_file("output.tga");

   return 0;
}
