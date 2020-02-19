#include "Vec3f.h"
#include "Ray.h"
#include "Camera.h"
#include "Plane.h"
#include <iostream>
#include <vector>
#include <fstream>

Vec3f coordinateToRGB(Vec3f coordinate)
{
  if(coordinate == Vec3f(-1000000000, -1000000000, -1000000000))
  {
    return Vec3f(-1000000000, -1000000000, -1000000000);
  }
  if(coordinate.getZ() >= 255)
  {
    return Vec3f(0, 0, 255);
  }
  else
  {
    return Vec3f(0, 0, coordinate.getZ());
  }
}

int main()
{
	Ray r = Ray(Vec3f(0, 0, 0), Vec3f(0, 0, -1));
  Camera c = Camera(r, 30, 30, -1, 99, 99);
  Plane p = Plane(0, 0, -90, 100);

  c.render(p);
  std::vector<Vec3f> hits = c.getHitLocations();
  std::vector<Vec3f> colors;
  for(int i = 0; i <= hits.size(); i++)
  {
    Vec3f c = coordinateToRGB(hits[i]);
    colors.push_back(c);
  }

  std::ofstream f;
  f.open("data.txt");
  for(int i = 0; i <= colors.size(); i++)
  {
    f << "(" << colors[i].getX() << "," << colors[i].getY() << "," << colors[i].getZ() << ")\n";
  }
}