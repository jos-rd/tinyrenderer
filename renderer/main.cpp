#include "objloader.h"
#include "rasterisation.h"
#include "tgaimage.h"

#include <ranges>

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
   const auto width{400};
   const auto height{400};
   TGAImage image(width, height, TGAImage::RGB);

   // Parse OBJ file
   Model model{"test.obj"};
   if (const auto parseResult = model.parseObj(); !parseResult) {
      return 1;
   }

   // Draw
   for (const auto& face : model.getFaces()) {
      for (const auto i : views::iota(0, 3)) {
         const auto currentVertex = model.getVertex(face.m_vertexIndices.at(i));
         const auto nextVertex =
            model.getVertex(face.m_vertexIndices.at((i + 1) % 3));
         const int x0 = (currentVertex.x + 1.) * width / 2.;
         const int y0 = (currentVertex.y + 1.) * height / 2.;
         const int x1 = (nextVertex.x + 1.) * width / 2.;
         const int y1 = (nextVertex.y + 1.) * height / 2.;
         const auto line =
            Rasterisation::calculateLine(Point{x0, y0}, Point{x1, y1});
         plotPoints(image, line, red);
      }
   }
   image.flip_vertically();
   image.write_tga_file("output.tga");

   return 0;
}
