/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef __ATOM_PHYSICS_H__
#define __ATOM_PHYSICS_H__

#include "PlatformMacros.h"
#include "Collision.h"
#include "Vector3f.h"

ATOM_BEGIN

/* macro for gravity */
#define GRAVITY 9.8f


	/* class that holds the physics subsystem */
class ATOMAPI Physics : public Collision 
{ 
public:
	Physics();
	~Physics();

	void SetActivePhysics(bool active);
	void SetMass(float objectMass);

	void AddVelocity(Vector3f objVel);
	void AddVelocity(float x, float y, float z);

	void SetVelocity(Vector3f velocity);
	void SetVelocity(float x, float y, float z);
	Vector3f GetVelocity();

	void AddAcceleration(Vector3f objAccel);
	void AddAcceleration(float x, float y, float z);

	void SetAcceleration(Vector3f acceleration);
	void SetAcceleration(float x, float y, float z);
	Vector3f GetAcceleration();

	void UseGravity(bool flag);

private:
	bool useGravity;
	bool gravityApplied;
	bool isActive;

protected:
	float mass;

	Vector3f velocity;
	Vector3f acceleration;

	void ApplyPhysics();

};

ATOM_END

#endif // __ATOM_PHYSICS_H__