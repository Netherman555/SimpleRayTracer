#include "Material.h"

Material::Material(Vec3f Color)
{
  color = Color;
}

Material::Material()
{
  color = Vec3f(112, 112, 112);
}

Vec3f Material::getColor()
{
  return color;
}