/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Light.h"

ATOM_BEGIN

Light::Light()
: ambient(Color4::BLACK)
, diffuse(Color4(0.1f, 0.1f, 0.1f, 0.1f))
, specular(Color4::WHITE)
, position(Vector3f::ZERO)
, isActive(true)
{
}

/* function declared in update to add a light in the scene */
void Light::AddLight(int lightType) 
{
	LightType light;
	if(lightType == 65) light = Light1;
	if(lightType == 66) light = Light2;
	if(lightType == 67) light = Light3;
	if(lightType == 68) light = Light4;
	if(lightType == 69) light = Light5;
	if(lightType == 70) light = Light6;
	if(lightType == 71) light = Light7;
	if(lightType == 72) light = Light8;

	glPushMatrix();
	float tmpAmbient[] = {	ambient.r,	ambient.g,	ambient.b,	ambient.a	};
	float tmpDiffuse[] = {	diffuse.r,	diffuse.g,	diffuse.b,	diffuse.a	};
	float tmpSpecular[] = {	specular.r, specular.g, specular.b, specular.a	};

	glLightfv(light, GL_AMBIENT, tmpAmbient);
	glLightfv(light, GL_DIFFUSE, tmpDiffuse);
	glLightfv(light, GL_SPECULAR, tmpSpecular);

	float tmpPos[] = {position.x, position.y, position.z, 1.0f};
	glLightfv(light, GL_POSITION, tmpPos);

	if(isActive) 
    {
		//glEnable(GL_COLOR_MATERIAL);
		glEnable(light);
		//glEnable(GL_LIGHTING);
		//glEnable(GL_NORMALIZE);
	}
	else 
    {
		//glDisable(GL_COLOR_MATERIAL);
		glDisable(light);
		//glDisable(GL_LIGHTING);
		//glDisable(GL_NORMALIZE);
	}

	glPopMatrix();
}

void Light::SetActiveLight(bool active) 
{
	isActive = active;
}

void Light::SetPosition(Vector3f pos) 
{
	position = pos;
}

void Light::SetPosition(float x, float y, float z) 
{
	position = Vector3f(x, y, z);
}

void Light::SetAmbient(Color4 amb) 
{
	ambient = amb;
}

void Light::SetAmbient(float r, float g, float b, float a) 
{
	ambient = Color4(r, g, b, a);
}

void Light::SetDiffuse(Color4 diff) 
{
	diffuse = diff;
}

void Light::SetDiffuse(float r, float g, float b, float a) 
{
	diffuse = Color4(r, g, b, a);
}

void Light::SetSpecular(Color4 spec) 
{
	specular = spec;
}

void Light::SetSpecular(float r, float g, float b, float a) 
{
	specular = Color4(r, g, b, a);
}

ATOM_END