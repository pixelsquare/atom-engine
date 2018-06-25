/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_TRANSFORM_H_
#define _ATOM_TRANSFORM_H_

#include "PlatformMacros.h"
#include "Vector3f.h"
#include "Color3.h"
#include "Time.h"

ATOM_BEGIN

class ATOMAPI Transform : public Vector3f, public Time
{
public:
    Transform();
    ~Transform();

    virtual void SetColor(Color3 Color);
    virtual void SetColor(float Red, float Green, float Blue);
    Color3 GetColor();

    void SetPosition(Vector3f pos);
    void SetPosition(float x, float y, float z);
    Vector3f GetPosition();

    virtual void SetScale(Vector3f scl);
    virtual void SetScale(float sclX, float sclY, float sclZ);
    Vector3f GetScale();

    void SetRotation(float angle, Vector3f rotationAxis);
    float GetAngle();
    Vector3f GetRotationAxis();

private:
protected:
    Vector3f position;
    Vector3f scale;
    Color3 color;
    float angleRot; 
    Vector3f axis;
};

ATOM_END

#endif // _ATOM_TRANSFORM_H_