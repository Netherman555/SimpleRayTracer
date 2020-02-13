#include "Plane.h"

Plane::Plane(Vec3f a, Vec3f b, Vec3f c)
{
  Vec3f AB = b - a;
  Vec3f AC = c - a;

  Vec3f normal = AB.cross(AC);

  x = normal.getX();
  y = normal.getY();
  z = normal.getZ();

  d = ((x * a.getX()) + (y * a.getY()) + (z * a.getZ())) * -1;
}

Plane::Plane(float a, float b, float c, float D)
{
  x = a;
  y = b;
  z = c;
  d = D;
}

float Plane::getX()
{
  return x;
}

float Plane::getY()
{
  return y;
}

float Plane::getZ()
{
  return z;
}

float Plane::getD()
{
  return d;
}
