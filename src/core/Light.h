/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_LIGHT_H_
#define _ATOM_LIGHT_H_

#include "PlatformMacros.h"
#include "PlatformGL.h"
#include "Vector3f.h"
#include "Color4.h"

ATOM_BEGIN

enum LightType
{
    Light1 = GL_LIGHT0,
    Light2 = GL_LIGHT1,
    Light3 = GL_LIGHT2,
    Light4 = GL_LIGHT3,
    Light5 = GL_LIGHT4,
    Light6 = GL_LIGHT5,
    Light7 = GL_LIGHT6,
    Light8 = GL_LIGHT7
};

/* class that holds the lighting subsystem */
class ATOMAPI Light 
{
public:
    Light();
    ~Light();

	void AddLight(int lightType);

	void SetActiveLight(bool active);

	void SetPosition(Vector3f position);
	void SetPosition(float x, float y, float z);

	void SetAmbient(Color4 ambient);
	void SetAmbient(float r, float g, float b, float a);

	void SetDiffuse(Color4 diffuse);
	void SetDiffuse(float r, float g, float b, float a);

	void SetSpecular(Color4 specular);
	void SetSpecular(float r, float g, float b, float a);

private:
	Vector3f position;
	Color4 ambient;
	Color4 diffuse;
	Color4 specular;
	bool isActive;

protected:
};

ATOM_END

#endif // _ATOM_LIGHT_H_