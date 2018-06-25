/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_ENGINE_H_
#define _ATOM_ENGINE_H_

#include "StdC.h"
#include "PlatformGL.h"
#include "PlatformMacros.h"

#include "Camera.h"
#include "Collision.h"
#include "GameObject.h"
#include "Input.h"
#include "Light.h"
#include "Particle.h"
#include "Physics.h"
#include "Raycast.h"
#include "Sound.h"
#include "Text.h"
#include "Time.h"
#include "Transform.h"
#include "Mathf.h"
#include "Vector3f.h"
#include "Color3.h"
#include "Color4.h"

/* generic data types defined in atom engine manner */
typedef unsigned int    AEenum;
typedef unsigned char   AEboolean;
typedef signed char     AEbyte;
typedef short           AEshort;
typedef int             AEint;
typedef int             AEsizei;
typedef float           AEfloat;
typedef float           AEclampf;
typedef double          AEdouble;
typedef double          AEclampd;
typedef void            AEvoid;

#define AE_SOLID_CUBE		0x32	//"Assets\\Cube.obj"
#define AE_SOLID_PLANE		0x33	//"Assets\\Plane.obj"
#define AE_SOLID_SPHERE		0x34	//"Assets\\Sphere.obj"
#define AE_SOLID_CAPSULE	0x35	//"Assets\\Capsule.obj"
#define AE_SOLID_CONE		0x36	//"Assets\\Cone.obj"
#define AE_SOLID_CYLINDER	0x37	//"Assets\\Cylinder.obj"
#define AE_SOLID_PYRAMID	0x38	//"Assets\\Pyramid.obj"
#define AE_SOLID_TORUS		0x39	//"Assets\\Torus.obj"

#define AE_LIGHT1	0x41
#define AE_LIGHT2	0x42
#define AE_LIGHT3	0x43
#define AE_LIGHT4	0x44
#define AE_LIGHT5	0x45
#define AE_LIGHT6	0x46
#define AE_LIGHT7	0x47
#define AE_LIGHT8	0x48

#ifndef ATOM_API_VERSION		/* allow this to be overriden */
    #define ATOM_API_VERSION	1	/* atom engine api version */
#endif

#if (ATOM_API_VERSION >= 1)

ATOM_BEGIN

	/* important functions to be declared in main */
	extern void ATOMAPI atomStartFunc( void(*func)(void) );
	extern void ATOMAPI atomUpdateFunc( void(*func)(void) );
	extern void ATOMAPI atomInitialize(int argc, char **argv);

	/* additional window settings for atom engine window */
	extern void ATOMAPI atomWindowWidth(int width);
	extern void ATOMAPI atomWindowHeight(int height);
	extern void ATOMAPI atomWindowName(char *name);
	extern void ATOMAPI atomWindowBGColor(double r, double g, double b, double a);

ATOM_END

#endif // (ATOM_API_VERSION >= 1)

#endif // _ATOM_ENGINE_H_