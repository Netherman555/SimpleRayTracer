#include "Camera.h"
#include <math.h>

//sohcahtoa

Camera::Camera(Ray cameraRay, int Fov, int FovY, int clippingDistance, int resolutionX, int resolutionY)
{
	cameraPoint = cameraRay.getOrigin();
	direction = cameraRay.getDirection();
	fov = Fov;
	clipDistance = clippingDistance;

	cameraPlaneWidth = tan(fov / 2) * clipDistance;
	cameraPlaneHeight = tan(FovY / 2) * clipDistance;

	
}

Camera::Camera()
{
	cameraPoint = Vec3f(0, 0, 0);
	direction = Vec3f(1, 0, 0);
}