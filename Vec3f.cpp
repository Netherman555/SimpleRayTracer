#include "Vec3f.h"
#include <iostream>

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

float Vec3f::dot(Vec3f vector)
{
  float newX = x * vector.getX();
  float newY = y * vector.getY();
  float newZ = z * vector.getZ();

  return newX + newY + newZ; 
}

Vec3f Vec3f::cross(Vec3f vector)
{
  float newX = (y * vector.getZ()) - (z * vector.getY());
  float newY = ((x * vector.getZ()) - (z * vector.getX())) * -1;
  float newZ = (x * vector.getY()) - (y * vector.getX());

  return Vec3f(newX, newY, newZ);
}
