#pragma once  
//Basic plane equation class

#include "Vec3f.h"
#include "Ray.h"

class Plane
{
  private:
    double x, y, z, d;
  public:
    Plane(Vec3f a, Vec3f b, Vec3f c); //Makes an equation from three points
    Plane(double a, double b, double c, double d); //Makes a Plane object from an equation itself.

    //Get Methods
    double getX();
    double getY();
    double getZ();
    double getD();

    //Collision Methods
    Vec3f findCollision(Ray ray);

};
