#include "Vec3f.h"
#include "Ray.h"
#include "Camera.h"
#include "Plane.h"
#include <iostream>
#include <vector>

int main()
{
	Ray r = Ray(Vec3f(0, 0, 0), Vec3f(0, 0, -1));
  Camera c = Camera(r, 30, 30, -1, 99, 99);
  Plane p = Plane(2, 2, 2, 36);

  c.render(p);
  std::vector<Vec3f> hits = c.getHitLocations();
  for(int i = 0; i <= 100; i++)
  {
    std::cout << i + 1 << " ( " << hits[i].getX() << " , " << hits[i].getY() << " , " << hits[i].getZ() << " ) " << std::endl;
  }
}