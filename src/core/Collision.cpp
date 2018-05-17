/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Collision.h"
#include "PlatformGL.h"

ATOM_BEGIN

Collision::Collision() 
: colliderOffset(Vector3f::ONE)
, initCollider(false)
, isActive(true)
, applyCollision(true)
, radius(1.0f)
, minDistance(0.0f)
, distance(0.0f)
, relativePos(Vector3f::ZERO)
, colliderType(ColliderType::Cube)
{
}

Collision::~Collision() { }

void Collision::SetActiveCollider(bool active) 
{
	this->isActive = active;
}

void Collision::SetActiveCollision(bool active) 
{
	this->applyCollision = active;
}

void Collision::SetColliderType(ColliderType type) 
{
	this->colliderType = type;
}

void Collision::SetColliderRadius(float rad) 
{
	if(this->radius != rad) 
    {
		this->RescaleSphere(rad);
	}
}

void Collision::SetColliderSize(Vector3f size) 
{
	if(this->colliderOffset != size) 
    {
		this->RescaleCube(size);
	}
}

void Collision::SetColliderSize(float x, float y, float z) 
{
	if(this->colliderOffset != Vector3f(x, y, z)) 
    {
		this->RescaleCube(Vector3f(x, y, z));
	}
}

bool Collision::HasCollidedWith(Collision &object) 
{
    if(!this->applyCollision)
    {
        return false;
    }

	if(this->colliderType && object.colliderType == Cube ||
		this->colliderType == Sphere && object.colliderType == Cube) 
    {
		bool xHasNotCollided =
			this->GetPosition().x - this->colliderOffset.x >
			object.GetPosition().x + object.colliderOffset.x ||
			this->GetPosition().x + this->colliderOffset.x <
			object.GetPosition().x - object.colliderOffset.x;

		bool yHasNotCollided = 
			this->GetPosition().y - this->colliderOffset.y >
			object.GetPosition().y + object.colliderOffset.y ||
			this->GetPosition().y + this->colliderOffset.y <
			object.GetPosition().y - object.colliderOffset.y;

		bool zHasNotCollided = 
			this->GetPosition().z - this->colliderOffset.z >
			object.GetPosition().z + object.colliderOffset.z ||
			this->GetPosition().z + this->colliderOffset.z <
			object.GetPosition().z - object.colliderOffset.z;

        if((xHasNotCollided || yHasNotCollided || zHasNotCollided))
        {
            return false;
        }			
        else
        {
            return true;
        }
	}
	else 
    {
		Vector3f obj1Pos = this->GetPosition();
		Vector3f obj2Pos = object.GetPosition();

		this->relativePos = obj1Pos - obj2Pos;
		this->distance = this->relativePos.Dot(this->relativePos, this->relativePos);
		this->minDistance = this->radius + object.radius;

        if(this->distance <= this->minDistance * this->minDistance)
        {
            return true;
        }
        else
        {
            return false;
        }
	}
}

void Collision::DrawCollider() 
{
	if(!this->isActive)
    {
        return;
    }

	if(!this->initCollider) 
    {
		if(colliderType == ColliderType::Cube) 
        {
			this->RescaleCube(this->colliderOffset);
		}

		if(colliderType == ColliderType::Sphere) 
        {
			this->RescaleSphere(this->radius);
		}

		this->initCollider = true;
	}

	glPushMatrix();
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glRotatef(this->angleRot, this->axis.x, this->axis.y, this->axis.z);
	glVertexPointer(3, GL_FLOAT, 0, this->cubeVertices);
	glColorPointer(3, GL_FLOAT, 0, this->cubeColor);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glDrawArrays(this->drawingType, 0, this->connectedPts);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glPopMatrix();
}

void Collision::RescaleCube(Vector3f scl) 
{
	this->cubeVertices = new Vector3f[24];
	this->cubeColor = new Color3[24];
	this->colliderOffset = scl;

	// Front Part
	this->cubeVertices[0] = Vector3f(this->colliderOffset.x, this->colliderOffset.y, this->colliderOffset.z);
	this->cubeVertices[1] = Vector3f(this->colliderOffset.x, -this->colliderOffset.y, this->colliderOffset.z);

	this->cubeVertices[2] = this->cubeVertices[1];
	this->cubeVertices[3] = Vector3f(-this->colliderOffset.x, -this->colliderOffset.y, this->colliderOffset.z);

	this->cubeVertices[4] = this->cubeVertices[3];
	this->cubeVertices[5] = Vector3f(-this->colliderOffset.x, this->colliderOffset.y, this->colliderOffset.z);

	this->cubeVertices[6] = this->cubeVertices[5];
	this->cubeVertices[7] = this->cubeVertices[0];

	// Back Part
	this->cubeVertices[8] = Vector3f(this->colliderOffset.x, this->colliderOffset.y, -this->colliderOffset.z);
	this->cubeVertices[9] = Vector3f(this->colliderOffset.x, -this->colliderOffset.y, -this->colliderOffset.z);

	this->cubeVertices[10] = this->cubeVertices[9];
	this->cubeVertices[11] = Vector3f(-this->colliderOffset.x, -this->colliderOffset.y, -this->colliderOffset.z);

	this->cubeVertices[12] = this->cubeVertices[11];
	this->cubeVertices[13] = Vector3f(-this->colliderOffset.x, this->colliderOffset.y, -this->colliderOffset.z);

	this->cubeVertices[14] = this->cubeVertices[13];
	this->cubeVertices[15] = this->cubeVertices[8];
			
	// Connections
	this->cubeVertices[16] = this->cubeVertices[0];
	this->cubeVertices[17] = this->cubeVertices[8];

	this->cubeVertices[18] = this->cubeVertices[1];
	this->cubeVertices[19] = this->cubeVertices[9];

	this->cubeVertices[20] = this->cubeVertices[3];
	this->cubeVertices[21] = this->cubeVertices[11];
			
	this->cubeVertices[22] = this->cubeVertices[5];
	this->cubeVertices[23] = this->cubeVertices[13];

	int i = 0;
	while(i < 24) 
    {
		this->cubeColor[i] = Color3(0.0f, 1.0f, 0.0f);
		i++;
	}

	this->drawingType = GL_LINES;
	this->connectedPts = 24;
}

void Collision::RescaleSphere(float rad) 
{
	this->cubeVertices = new Vector3f[1080];
	this->cubeColor = new Color3[1080];
	this->radius = rad;

	int j = -80;
	for(int i = 0; i < 1080; i++) 
    {
		float theta = 2 * 3.1415926f * i / 300;

        if(i <= 375)
        {
            this->cubeVertices[i] = Vector3f(cos(theta), sin(theta), 0.0f) * this->radius;
        }
        else if(i > 375 && i <= 750)
        {
            this->cubeVertices[i] = Vector3f(0.0f, sin(theta), cos(theta)) * this->radius;
        }
		else if(i > 750) 
        {
			theta =  2 * 3.1415926f * j / 300;
			this->cubeVertices[i] = Vector3f(cos(theta), 0.0f, sin(theta)) * this->radius;
			j++;
		}

		this->cubeColor[i] = Color3(0.0f, 1.0f, 0.0f);
	}

	this->drawingType = GL_LINE_STRIP;
	this->connectedPts = 1080;
}

ATOM_END