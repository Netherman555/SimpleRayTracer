#include "Vec3f.h"
#include <iostream>



//Creates a vector with 3 doubles
Vec3f::Vec3f(double X, double Y, double Z)
{
  x = X;
  y = Y;
  z = Z;
}

//Creates a vector with 0's for all doubles
Vec3f::Vec3f()
{
  x = 0;
  y = 0;
  z = 0;
}

//Returns X value of Vector
double Vec3f::getX()
{
  return x;
}

//Returns Y value of Vector
double Vec3f::getY()
{
  return y;
}

//Returns Z value of Vector
double Vec3f::getZ()
{
  return z;
}

double Vec3f::dot(Vec3f vector)
{
  double newX = x * vector.getX();
  double newY = y * vector.getY();
  double newZ = z * vector.getZ();

  return newX + newY + newZ; 
}

Vec3f Vec3f::cross(Vec3f vector)
{
  double newX = (y * vector.getZ()) - (z * vector.getY());
  double newY = ((x * vector.getZ()) - (z * vector.getX())) * -1;
  double newZ = (x * vector.getY()) - (y * vector.getX());

  return Vec3f(newX, newY, newZ);
}
