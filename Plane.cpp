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

Plane::Plane(double a, double b, double c, double D)
{
  x = a;
  y = b;
  z = c;
  d = D;
}

double Plane::getX()
{
  return x;
}

double Plane::getY()
{
  return y;
}

double Plane::getZ()
{
  return z;
}

double Plane::getD()
{
  return d;
}

Vec3f Plane::findCollision(Ray ray)
{
  Vec3f origin = ray.getOrigin();
  Vec3f direction = ray.getDirection();

  double pXD = direction.getX() * x;
  double pYD = direction.getY() * y;
  double pZD = direction.getZ() * z;

  double pXO = origin.getX() * x;
  double pYO = origin.getY() * y;
  double pZO = origin.getZ() * z;

  double pO = pXO + pYO + pZO;
  double pD = pXD + pYD + pZD;

  double tempD = d * 1;
  tempD -= pO;
  double t = tempD / pD;

  return Vec3f((t*direction.getX() + origin.getX()),(t*direction.getY() + origin.getY()),(t*direction.getZ() + origin.getZ()));
}
