/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Transform.h"

ATOM_BEGIN

Transform::Transform()
: position(Vector3f::ZERO)
, scale(Vector3f::ONE)
, color(Color3::WHITE)
, angleRot(0.0f)
, axis(Vector3f::UP)
{
}

Transform::~Transform()
{
    position = Vector3f::ZERO;
    scale = Vector3f::ZERO;
    color = Color3::BLACK;
    angleRot = 0.0f;
    axis = Vector3f::ZERO;
}

void Transform::SetColor(Color3 Color) 
{
	this->color = Color;
}

void Transform::SetColor(float r, float g, float b) 
{
	this->color = Color3(r, g, b);
}

Color3 Transform::GetColor() 
{ 
	return this->color;
}

void Transform::SetPosition(Vector3f pos) 
{
	this->position = pos;
}

void Transform::SetPosition(float x, float y, float z) 
{
	this->position = Vector3f(x, y, z);
}

Vector3f Transform::GetPosition() 
{ 
	return this->position; 
}

void Transform::SetScale(Vector3f scl) 
{
	this->scale = scl;
}

void Transform::SetScale(float sclX, float sclY, float sclZ) 
{
	this->scale = Vector3f(sclX, sclY, sclZ);
}

Vector3f Transform::GetScale() 
{
	return this->scale; 
}

void Transform::SetRotation(float angle, Vector3f rotationAxis) 
{
	this->angleRot = angle;
	this->axis = rotationAxis;
}

float Transform::GetAngle() 
{ 
	return this->angleRot; 
}

Vector3f Transform::GetRotationAxis() 
{
	return this->axis; 
}

ATOM_END