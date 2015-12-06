#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "math3d.h"

class Camera {
public:
	Camera();
	~Camera();
	
	void StartUp();
	void Orbit(int mX, int mY, int relX, int relY);
	void lookAt(const vec3& e, const vec3& d, const vec3& u);
	void update();
	void reset();

	vec3 eye; // point of reference
	vec3 dir; // view direction
	vec3 up;  // orientation

	mat4 c;		// camera matrix
	mat4 ci;	// inverse camera matrix

	
};

#endif