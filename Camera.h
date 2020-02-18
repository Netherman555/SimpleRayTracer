#include "Ray.h"
#include "Vec3f.h"
#include "Plane.h"
#include <math.h>
#include <vector>
#include <iostream>

class Camera
{
  private:
    Vec3f cameraPoint; //Camera origin point
    Vec3f cameraDirection; //Direction vector of camera
    int xFov, yFov; //FOV, in degrees, in x and y axis
    int clippingDistance; //Distance from camera point to camera plane
    int resolutionX, resolutionY; //Resolution in x and y axis

    int planeWidth, planeHeight; //Width and height of intersect plane

    //Pixel Location functions
    Vec3f RasterToNDC(Vec3f rasterCoordinate); //Turns a Raster Coordinate to a NDC coordinate.  Uses Vec3f with Z empty.
    Vec3f NDCToScreen(Vec3f ndcCoordinate); //Turns a NDC Coordinate to a Screen Coordinate.  Uses Vec3f with Z empty.
    Vec3f ScreenToWorld(Vec3f screenCoordinate); //Turns a screen coordinate into a 3d world coordinate

    std::vector<Vec3f> pixelLocations;
    std::vector<Vec3f> hitLocations;
  public:
    Camera(Ray cameraRay, int xFOV, int yFOV, double ClippingDistance, int ResolutionX, int ResolutionY); //Creates a camera and arranges all pixel locations.

    //Get Methods
    std::vector<Vec3f> getPixelLocations();
    std::vector<Vec3f> getHitLocations();

    //Rendering functions
    void render(Plane renderObject);
};
