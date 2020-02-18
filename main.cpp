#include "Vec3f.h"
#include "Ray.h"
#include "Camera.h"
#include "Plane.h"
#include <iostream>
#include <vector>

int main()
{
	Ray r = Ray(Vec3f(0, 0, 0), Vec3f(0, 0, -1));
  Camera c = Camera(r, 30, 30, -1, 5, 5);
  std::vector<Vec3f> v = c.getPixelLocations();
}