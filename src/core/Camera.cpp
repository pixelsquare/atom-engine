/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Camera.h"

ATOM_BEGIN

Window atomWindow;
Camera atomCamera;
CameraEditMode editMode;

void atomCameraPosition(Vector3f position) 
{
	atomCamera.position = position;
}

void atomCameraPosition(float x, float y, float z)
{
	atomCamera.position = Vector3f(x, y, z);
}

void atomCameraLookAt(Vector3f lookAt) {
	atomCamera.lookAt = lookAt;
}

void atomCameraLookAt(float x, float y, float z)
{
	atomCamera.lookAt = Vector3f(x, y, z);
}

void atomCameraUp(Vector3f up)
{
	atomCamera.up = up;
}

void atomCameraUp(float x, float y, float z)
{
	atomCamera.up = Vector3f(x, y, z);
}

void atomEditMode(bool flag)
{
	editMode.position.z = atomCamera.lookAt.z;
	//inEditMode = flag;
}

ATOM_END