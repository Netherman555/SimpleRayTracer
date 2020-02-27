#include "Light.h"

Light::Light(Vec3f Position, Vec3f Color, double Intensity)
{
  position = Position;
  color = Color;
  intensity = Intensity;
}

Vec3f Light::getPosition()
{
  return position;
}

Vec3f Light::getColor()
{
  return color;
}

int Light::getIntensity()
{
  return intensity;
}