/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_VECTOR3F_H_
#define _ATOM_VECTOR3F_H_

#include "PlatformMacros.h"

ATOM_BEGIN

class Vector3f
{
public:
    Vector3f();
    // Vector3f(float vecX, float vecY, float vecZ);
    ~Vector3f();

    // Vector3f &operator=(const Vector3f &rhs);
    // Vector3f &operator-() const;

    // Vector3f &operator+=(const Vector3f &rhs);
    // Vector3f operator+(const Vector3f &op);

    // Vector3f &operator-=(const Vector3f &rhs);
    // Vector3f operator-(const Vector3f &op);

    // Vector3f &operator*=(const float scalar);
    // Vector3f operator*(const float scalar);

    // Vector3f &operator*=(const Vector3f &rhs);
    // Vector3f operator*(const Vector3f &op);

    // Vector3f &operator/=(const float scalar);
    // Vector3f operator/(const float scalar);

    // Vector3f &operator/=(const Vector3f &rhs);
    // Vector3f operator/(const Vector3f &op);

    // bool operator==(const Vector3f &other);
    // bool operator!=(const Vector3f &other);

    // bool operator>(const Vector3f &other);
    // bool operator>=(const Vector3f &other);

    // bool operator<(const Vector3f &other);
    // bool operator<=(const Vector3f &other);

    // float Length();
    // Vector3f &Normalize();

    // float Dot(const Vector3f& vec1, const Vector3f& vec2);
    // Vector3f Cross(const Vector3f& vec1, const Vector3f& vec2);

    // void Print();

    // static Vector3f ZERO;	static Vector3f FRONT;
    // static Vector3f ONE;		static Vector3f BACK;
    // static Vector3f UP;		static Vector3f RIGHT;
    // static Vector3f DOWN;	static Vector3f LEFT;

    float x;
    float y;
    float z;
private:
protected:
};

ATOM_END

#endif // _ATOM_VECTOR3F_H_