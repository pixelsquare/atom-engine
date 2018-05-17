/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef __ATOM_RAYCAST_H__
#define __ATOM_RAYCAST_H__

#include "PlatformMacros.h"
#include "GameObject.h"
#include "Vector3f.h"

/* 
	Raycast subsystem 
	credits to: Mr. Ryan Baclit (professor)
*/

ATOM_BEGIN

class ATOMAPI Raycast
{
public:
    Raycast();
    ~Raycast();

    static void RayPick(float x, float y);
    static void DrawRay(int length, Vector3f &vec);
    static bool CheckRayHit(GameObject &object);

private:
protected:
};

ATOM_END

#endif // __ATOM_RAYCAST_H__