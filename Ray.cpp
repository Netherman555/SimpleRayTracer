#include "Ray.h"

Ray::Ray(Vec3f Origin, Vec3f PointOne)
{
  //Uses parametric equation x = (1-t*)Origin + t*Direction

  pOrigin = Origin;
  pDirection = Vec3f(PointOne.getX() - pOrigin.getX(), PointOne.getY() - pOrigin.getY(), PointOne.getZ() - pOrigin.getZ());
}

Vec3f Ray::getOrigin()
{
  return pOrigin;
}

Vec3f Ray::getDirection()
{
  return pDirection;
}
