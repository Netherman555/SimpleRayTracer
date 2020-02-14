  
//Basic plane equation class

#include "Vec3f.h"
#include "Ray.h"

class Plane
{
  private:
    float x, y, z, d;
  public:
    Plane(Vec3f a, Vec3f b, Vec3f c); //Makes an equation from three points
    Plane(float a, float b, float c, float d); //Makes a Plane object from an equation itself.

    //Get Methods
    float getX();
    float getY();
    float getZ();
    float getD();

    //Collision Methods
    Vec3f findCollision(Ray ray);

};
