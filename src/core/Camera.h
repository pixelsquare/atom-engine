/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_CAMERA_H_
#define _ATOM_CAMERA_H_

#include "PlatformMacros.h"
#include "Color4.h"
#include "Vector3f.h"

ATOM_BEGIN

/* Window Properties */
struct Window 
{
	Window() 
    {
		this->windowHandle = 0;
		this->width = 800;
		this->height = 600;
		this->name = "Atom Engine v2.0 Project";
		this->color = Color4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	int windowHandle;
	const char *name;
	int width;
	int height;
	Color4 color;

}; extern Window atomWindow;

/* Camera Properties */
struct Camera
{
    Camera()
    {
		this->position = Vector3f(0.0f, 0.0f, 10.0f);
		this->lookAt = Vector3f(0.0f, 0.0f, 0.0f);
		this->up = Vector3f(0.0f, 1.0f, 0.0f);
	}

	Vector3f position;
	Vector3f lookAt;
	Vector3f up;

}; extern Camera atomCamera;

/* Atom Engine edit mode properties */
struct CameraEditMode 
{
	CameraEditMode() 
    {
		this->position = Vector3f(0.01f, 0.01f, 10.0f);
		this->rotation = Vector3f(0.01f, 0.01f, 0.0f);
		this->lastX = 0;
		this->lastY = 0;
		this->mouseClick[0] = false;
		this->mouseClick[1] = false;
		this->mouseClick[2] = false;
	}

	Vector3f position;
	Vector3f rotation;
	int lastX;
	int lastY;
	bool mouseClick[3];

}; extern CameraEditMode editMode;

static bool inEditMode;

/* Functions that exported and can be used outside  */
extern void ATOMAPI atomCameraPosition(Vector3f position);
extern void ATOMAPI atomCameraPosition(float x, float y, float z);

extern void ATOMAPI atomCameraLookAt(Vector3f lookAt);
extern void ATOMAPI atomCameraLookAt(float x, float y, float z);

extern void ATOMAPI atomCameraUp(Vector3f up);
extern void ATOMAPI atomCameraUp(float x, float y, float z);

extern void ATOMAPI atomEditMode(bool flag);

ATOM_END

#endif // _ATOM_CAMERA_H_