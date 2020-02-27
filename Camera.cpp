#include "Camera.h"

Camera::Camera(Ray cameraRay, int xFOV, int yFOV, double ClippingDistance, int ResolutionX, int ResolutionY)
{
  cameraPoint = cameraRay.getOrigin();
  cameraDirection = cameraRay.getDirection();

  xFov = xFOV;
  yFov = yFOV;

  clippingDistance = ClippingDistance;

  resolutionX = ResolutionX;
  resolutionY = ResolutionY;

  planeWidth = tan(xFov / 2) * clippingDistance;
  planeHeight = tan(yFov / 2) * clippingDistance;

  //Initializes all pixel positions for rendering
  Vec3f currentPixel; //2D representation of the pixel on the screen
  Vec3f pixelWorld; //Final pixel.  Both are cleared.
  for(int y = 0; y <= resolutionY; y++)
  {
    for(int x = 0; x <= resolutionX; x++)
    {
      currentPixel = Vec3f(x, y, 0);
      pixelWorld = RasterToNDC(currentPixel);
      pixelWorld = NDCToScreen(pixelWorld);
      pixelWorld = ScreenToWorld(pixelWorld);
      pixelLocations.push_back(pixelWorld);
    }
  }
}

Vec3f Camera::RasterToNDC(Vec3f rasterCoordinate)
{
  double newX = (rasterCoordinate.getX() + 0.5) / resolutionX;
  double newY = (rasterCoordinate.getY() + 0.5) / resolutionY;

  return Vec3f(newX, newY, 0);
}

Vec3f Camera::NDCToScreen(Vec3f ndcCoordinate)
{
  double newX = 2 * ndcCoordinate.getX() - 1;
  double newY = 1 - 2 * ndcCoordinate.getY();

  return Vec3f(newX, newY, 0);
}

Vec3f Camera::ScreenToWorld(Vec3f screenCoordinate)
{
  return Vec3f(screenCoordinate.getX(), screenCoordinate.getY(), cameraDirection.getZ());
}

std::vector<Vec3f> Camera::getPixelLocations()
{
  return pixelLocations;
}

std::vector<Vec3f> Camera::getPixelColors()
{
  return pixelColors;
}

void Camera::render(std::vector<Plane> renderObjects, std::vector<Light> lightObjects)
{
  double closest = 1000000000000000000; //Distance to current closest intersection
  double current;
  int currentPlane;

  for(int i = 0; i < pixelLocations.size(); i++)
  {
      for(int f = 0; f < renderObjects.size(); f++)
      {
        current = renderObjects[f].findT(Ray(cameraPoint, pixelLocations[i]));
        if(current == -1000000000)
        {
          closest = closest;
          currentPlane = currentPlane;
        }
        else if(current < closest) 
        {
          closest = current; 
          currentPlane = f;
        }

        Vec3f intersectPoint = Ray(cameraPoint, pixelLocations[i]).getFromT(closest);
        for(int z = 0; z < renderObjects.size(); z++)
        {
          for(int l = 0; l < lightObjects.size(); l++)
          {
            
          }
        }
      }
  }
}
