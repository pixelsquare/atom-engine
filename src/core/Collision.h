/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_COLLISION_H_
#define _ATOM_COLLISION_H_

#include "PlatformMacros.h"
#include "Transform.h"

ATOM_BEGIN

/* Options for the collider type */
enum class ColliderType
{
	None, Cube, Sphere
};

/* Class that holds the collision detection subsystem */
class ATOMAPI Collision : public Transform 
{
public:
	Collision();
	~Collision();

	void SetActiveCollider(bool active);			// Active Collider Box
	void SetActiveCollision(bool active);			// Active Collision Detection
	void SetColliderType(ColliderType type);

	void SetColliderRadius(float rad);
	void SetColliderSize(Vector3f size);
	void SetColliderSize(float x, float y, float z);

	bool HasCollidedWith(Collision &object);

	Vector3f colliderOffset;

private:
	Vector3f* cubeVertices;
	Color3* cubeColor;

	bool isActive;
	bool applyCollision;
	float radius;
	float minDistance;
	float distance;
	Vector3f relativePos;

	int drawingType;
	long connectedPts;
	bool initCollider;
protected:
	void DrawCollider();
	void RescaleCube(Vector3f scl);
	void RescaleSphere(float rad);

	ColliderType colliderType;
};

ATOM_END

#endif // _ATOM_COLLISION_H_