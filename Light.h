#pragma once

#include "Vec3f.h"

class Light
{
  private:
    Vec3f position;
    Vec3f color;
    double intensity;
  public:
    //Constructors
    Light(Vec3f Position, Vec3f Color, double Intensity);

    //Get Methods
    Vec3f getPosition();
    Vec3f getColor();
    int getIntensity();
};