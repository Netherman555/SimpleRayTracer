#include "Vec3f.h"

#ifndef __RAY_INCLUDE__
#define __RAY_INCLUDE__

class Ray
{
  private:
    Vec3f pOrigin;
    Vec3f pDirection;
  public:
    Ray(Vec3f Origin, Vec3f Direction);

    //Get Methods
    Vec3f getOrigin();
    Vec3f getDirection();
};

#endif
