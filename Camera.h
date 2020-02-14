#pragma once
#include "Ray.h"
#include "Vec3f.h"

class Camera
{
private:
	Vec3f cameraPoint;
	Vec3f direction;
	int fov;
	int clipDistance;

	int cameraPlaneWidth;
	int cameraPlaneHeight;

	double 
public:
	Camera(Ray cameraRay, int fov, int clippingDistance); //Defines a camera using ray as the starting position and direction.
	Camera(); //Defines a camera with a starting position of (0, 0, 0) and a direction of (1, 0, 0)
};