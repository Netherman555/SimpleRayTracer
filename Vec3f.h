/*
Basic Vector class.

Holds three floats, can do the majority of vector math
*/

class Vec3f
{
  private:
    //Private Variables
    float x, y, z;

  public:
    //Constructors
    Vec3f(float x, float y, float z); //Creates a vector with 3 floats
    Vec3f(); //Creates a vector with 0's for all floats

    //Get Methods
    float getX();
    float getY();
    float getZ();

    //Vector Math Methods
    float dot(Vec3f vector)
    {
      float newX = x * vector.getX();
      float newY = y * vector.getY();
      float newZ = z * vector.getZ();

      return newX + newY + newZ;
    }

    //Operators
    Vec3f operator + (Vec3f vector) 
    {
      float newX = vector.getX() + x;
      float newY = vector.getY() + y;
      float newZ = vector.getZ() + z;

      return Vec3f(newX, newY, newZ);
    }

    Vec3f operator - (Vec3f vector)
    {
      float newX = x - vector.getX();
      float newY = y - vector.getY();
      float newZ = z - vector.getZ();

      return Vec3f(newX, newY, newZ);
    }

    Vec3f operator * (float f)
    {
      float newX = x * f;
      float newY = x * y;
      float newZ = x * z;

      return Vec3f(newX, newY, newZ);
    }


};
