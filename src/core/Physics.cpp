/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Physics.h"

ATOM_BEGIN

Physics::Physics() 
: mass(1.0f)
, velocity(Vector3f::ZERO)
, acceleration(Vector3f::ZERO)
, useGravity(false)
, gravityApplied(false)
, isActive(true)
{
}

Physics::~Physics()
{
    mass = 0.0f;
    velocity = Vector3f::ZERO;
    acceleration = Vector3f::ZERO;
    useGravity = false;
    gravityApplied = false;
    isActive = false;
}

void Physics::SetActivePhysics(bool active)
{
	this->isActive = active;
}

void Physics::SetMass(float objectMass)
{
    if(objectMass > 0)
    {
        this->mass = objectMass;
    }
}

void Physics::AddVelocity(Vector3f objVel) 
{
	this->velocity += objVel;
}

void Physics::AddVelocity(float x, float y, float z) 
{
	this->velocity += Vector3f(x, y, z);
}

void Physics::SetVelocity(Vector3f vel) 
{
	this->velocity = vel;
}

void Physics::SetVelocity(float x, float y, float z) 
{
	this->velocity = Vector3f(x, y, z);
}

Vector3f Physics::GetVelocity() 
{
	return this->velocity;
}

void Physics::AddAcceleration(Vector3f objAccel) 
{
	this->acceleration += objAccel;
}

void Physics::AddAcceleration(float x, float y, float z) 
{
	this->acceleration += Vector3f(x, y, z);
}

void Physics::SetAcceleration(Vector3f accel) 
{
	this->acceleration = accel;
}

void Physics::SetAcceleration(float x, float y, float z) 
{
	this->acceleration = Vector3f(x, y, z);
}

Vector3f Physics::GetAcceleration() 
{
	return this->acceleration;
}

void Physics::UseGravity(bool flag) 
{
    if(!this->isActive)
    {
        return;
    }

	this->useGravity = flag;

	// When gravity is turned off 
	// Set the acceleration opposite to the current acceleration
	// this will cause to a constant velocity to the object

	if(!this->useGravity && this->gravityApplied) 
    {
        if(this->acceleration != Vector3f::ZERO)
        {
            this->AddAcceleration(Vector3f::UP * GRAVITY * this->mass);
        }

		this->gravityApplied = false;
	}

	// Gravity is Applied when this function is called
	// as well as the useGravity flag has been triggered
	// Set the acceleration -9.8 when the flag is true

	if(this->useGravity && !this->gravityApplied) 
    {
		this->acceleration = Vector3f::DOWN * GRAVITY * this->mass;
		this->gravityApplied = true;
	}
}

void Physics::ApplyPhysics() 
{
    if(!this->isActive)
    {
        return;
    }
	//float deltaTime = this->DeltaTime() * 2.0f;

	// Make the object move when the acceleration
	// is not zero

    if(this->acceleration != Vector3f::ZERO)
    {
        this->velocity += (this->acceleration * 0.2f) * 0.02f;
    }

	// Add the velocity to the position of the object

	this->position += this->velocity * 0.2f;
}

ATOM_END