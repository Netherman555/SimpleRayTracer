/*
Basic Vector class.
Holds three doubles, can do the majority of vector math
*/

#ifndef VEC3F_H
#define VEC3F_H

class Vec3f
{
  private:
    //Private Variables
    double x, y, z;

  public:
    //Constructors
    Vec3f(double x, double y, double z); //Creates a vector with 3 doubles
    Vec3f(); //Creates a vector with 0's for all doubles

    //Get Methods
    double getX();
    double getY();
    double getZ();

    //Vector Math Methods
    double dot(Vec3f vector);
    Vec3f cross(Vec3f vector);
    

    //Operators
    Vec3f operator + (Vec3f vector) 
    {
      double newX = vector.getX() + x;
      double newY = vector.getY() + y;
      double newZ = vector.getZ() + z;

      return Vec3f(newX, newY, newZ);
    }

    Vec3f operator - (Vec3f vector)
    {
      double newX = x - vector.getX();
      double newY = y - vector.getY();
      double newZ = z - vector.getZ();

      return Vec3f(newX, newY, newZ);
    }

    Vec3f operator * (double f)
    {
      double newX = x * f;
      double newY = x * y;
      double newZ = x * z;

      return Vec3f(newX, newY, newZ);
    }

    bool operator == (Vec3f vector)
    {
      if(vector.getX() == x && vector.getY() == y && vector.getZ() == z)
      {
        return true;
      }
      return false;
    }
};

#endif
