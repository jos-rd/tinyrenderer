#include <iostream>
#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

int main(int argc, char** argv)
{
   TGAImage image(100, 100, TGAImage::RGB);
   image.set(52, 41, red);
   image.flip_vertically(); // place origin at the left bottom corner of the image
   image.write_tga_file("output.tga");

   return 0;
}
