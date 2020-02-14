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

  pixelLocations.resize(resolutionX * resolutionY);

  //Initializes all pixel positions for rendering
  w
}
