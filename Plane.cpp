#include "Plane.h"

Plane::Plane(Vec3f a, Vec3f b, Vec3f c, Material M)
{
  Vec3f AB = b - a;
  Vec3f AC = c - a;

  Vec3f normal = AB.cross(AC);

  x = normal.getX();
  y = normal.getY();
  z = normal.getZ();

  d = ((x * a.getX()) + (y * a.getY()) + (z * a.getZ())) * -1;

  m = M;
}

Plane::Plane(double a, double b, double c, double D, Material M)
{
  x = a;
  y = b;
  z = c;
  d = D;

  m = M;
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

Material Plane::getMaterial()
{
  return m;
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

  if(t <= 1)
  {
    return Vec3f(-1000000000, -100000000, -1000000000);
  }

  return Vec3f((t*direction.getX() + origin.getX()),(t*direction.getY() + origin.getY()),(t*direction.getZ() + origin.getZ()));
}

double Plane::findT(Ray ray)
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

  if(t <= 1)
  {
    return -1000000000;
  }
  else{
    return t;
  }
}