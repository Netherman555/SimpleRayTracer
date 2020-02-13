#include "Vec3f.h"

//Creates a vector with 3 floats
Vec3f::Vec3f(float X, float Y, float Z)
{
  x = X;
  y = Y;
  z = Z;
}

//Creates a vector with 0's for all floats
Vec3f::Vec3f()
{
  x = 0;
  y = 0;
  z = 0;
}

//Returns X value of Vector
float Vec3f::getX()
{
  return x;
}

//Returns Y value of Vector
float Vec3f::getY()
{
  return y;
}

//Returns Z value of Vector
float Vec3f::getZ()
{
  return z;
}
