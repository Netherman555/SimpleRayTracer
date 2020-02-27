#include "Vec3f.h"
#include "Ray.h"
#include "Camera.h"
#include "Plane.h"
#include "Light.h"
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	Ray r = Ray(Vec3f(0, 0, 0), Vec3f(0, 0, -1));
  Camera c = Camera(r, 30, 30, -1, 99, 99);
  Material m = Material();
  Material m1 = Material(Vec3f(0, 0, 255));
  Plane p = Plane(0, 0, 90, -100, m);
  Plane p1 = Plane(0, 1, 90, -100, m1);

  std::vector<Plane> ps;
  ps.push_back(p);
  ps.push_back(p1);\

  std::vector<Light> ls;
  ls.push_back(Light(Vec3f(0, 0, 0), Vec3f(255, 255, 255), 0.1));

  c.render(ps, ls);

  std::vector<Vec3f> colors = c.getPixelColors();
  std::ofstream f;
  f.open("data.txt");
  for(int i = 0; i < colors.size(); i++)
  {
    f << "(" << colors[i].getX() << "," << colors[i].getY() << "," << colors[i].getZ() << ")\n";
  }
}