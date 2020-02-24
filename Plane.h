#pragma once  
//Basic plane equation class

#include "Vec3f.h"
#include "Ray.h"
#include "Material.h"

class Plane
{
  private:
    double x, y, z, d;
    Material m;
  public:
    Plane(Vec3f a, Vec3f b, Vec3f c, Material M); //Makes an equation from three points
    Plane(double a, double b, double c, double d, Material M); //Makes a Plane object from an equation itself.

    //Get Methods
    double getX();
    double getY();
    double getZ();
    double getD();
    Material getMaterial();

    //Collision Methods
    Vec3f findCollision(Ray ray);
    double findT(Ray ray);
};
