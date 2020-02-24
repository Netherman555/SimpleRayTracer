#include "Vec3f.h"

class Material
{
  private:
    Vec3f color;

  public:
    //Constructors
    Material(Vec3f Color);
    Material();

    //Get Methods
    Vec3f getColor();
};