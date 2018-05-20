/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Vector3f.h"
#include <stdio.h>

ATOM_BEGIN

// Vector3f Vector3f::ZERO	= Vector3f(0.0f, 0.0f, 0.0f);
// Vector3f Vector3f::ONE	= Vector3f(1.0f, 1.0f, 1.0f);
// Vector3f Vector3f::UP		= Vector3f(0.0f, 1.0f, 0.0f);
// Vector3f Vector3f::DOWN	= Vector3f(0.0f, -1.0f, 0.0f);
// Vector3f Vector3f::FRONT	= Vector3f(0.0f, 0.0f, 1.0f);
// Vector3f Vector3f::BACK	= Vector3f(0.0f, 0.0f, -1.0f);
// Vector3f Vector3f::RIGHT	= Vector3f(1.0f, 0.0f, 0.0f);
// Vector3f Vector3f::LEFT	= Vector3f(-1.0f, 0.0f, 0.0f);

Vector3f::Vector3f()
: x(0.0f)
, y(0.0f)
, z(0.0f)
{
}

Vector3f::Vector3f(float x, float y, float z)
: x(x)
, y(y)
, z(z)
{
}

Vector3f::~Vector3f() 
{ 
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

// Vector3f &Vector3f::operator=(const Vector3f &rhs)
// {
    // this->x = rhs.x;
    // this->y = rhs.y;
    // this->z = rhs.z;

    // return *this;
// }

// Vector3f &Vector3f::operator-() const
// {
    // Vector3f *tmp = new Vector3f;
    // *tmp = *this;
    // tmp->x = -tmp->x;
    // tmp->y = -tmp->y;
    // tmp->z = -tmp->z;
    // return *tmp;
// }

// Vector3f &Vector3f::operator+=(const Vector3f &rhs)
// {
    // this->x += rhs.x;
    // this->y += rhs.y;
    // this->z += rhs.z;

    // return *this;
// }

// Vector3f Vector3f::operator+(const Vector3f &op)
// {
    // Vector3f rhs;
    // rhs.x = this->x + op.x;
    // rhs.y = this->y + op.y;
    // rhs.z = this->z + op.z;

    // return rhs;
// }

// Vector3f &Vector3f::operator-=(const Vector3f &rhs)
// {
    // this->x -= rhs.x;
    // this->y -= rhs.y;
    // this->z -= rhs.z;

    // return *this;
// }

// Vector3f Vector3f::operator-(const Vector3f &op)
// {
    // Vector3f rhs;
    // rhs.x = this->x - op.x;
    // rhs.y = this->y - op.y;
    // rhs.z = this->z - op.z;

    // return rhs;
// }

// Vector3f &Vector3f::operator*=(const float scalar)
// {
    // this->x *= scalar;
    // this->y *= scalar;
    // this->z *= scalar;

    // return *this;
// }

// Vector3f Vector3f::operator*(const float scalar)
// {
    // Vector3f rhs;
    // rhs.x = this->x * scalar;
    // rhs.y = this->y * scalar;
    // rhs.z = this->z * scalar;

    // return rhs;
// }

// Vector3f &Vector3f::operator*=(const Vector3f &rhs)
// {
    // this->x *= rhs.x;
    // this->y *= rhs.y;
    // this->z *= rhs.z;

    // return *this;
// }

// Vector3f Vector3f::operator*(const Vector3f &op)
// {
    // Vector3f rhs;
    // rhs.x = this->x * op.x;
    // rhs.y = this->y * op.y;
    // rhs.z = this->z * op.z;

    // return rhs;
// }

// Vector3f &Vector3f::operator/=(const float scalar)
// {
    // this->x /= scalar;
    // this->y /= scalar;
    // this->z /= scalar;

    // return *this;
// }

// Vector3f Vector3f::operator/(const float scalar)
// {
    // Vector3f rhs;
    // rhs.x = this->x / scalar;
    // rhs.y = this->y / scalar;
    // rhs.z = this->z / scalar;

    // return rhs;
// }

// Vector3f &Vector3f::operator/=(const Vector3f &rhs)
// {
    // this->x /= rhs.x;
    // this->y /= rhs.y;
    // this->z /= rhs.z;

    // return *this;
// }

// Vector3f Vector3f::operator/(const Vector3f &op)
// {
    // Vector3f rhs;
    // rhs.x = this->x / op.x;
    // rhs.y = this->y / op.y;
    // rhs.z = this->z / op.z;

    // return rhs;
// }

// bool Vector3f::operator==(const Vector3f &other)
// {
    // return (this->x == other.x && this->y == other.y && this->z == other.z);
// }

// bool Vector3f::operator!=(const Vector3f &other)
// {
    // return (this->x != other.x || this->y != other.y || this->z != other.z);
// }

// bool Vector3f::operator>(const Vector3f &other)
// {
    // return (this->x > other.x || this->y > other.y || this->z > other.z);
// }

// bool Vector3f::operator>=(const Vector3f &other)
// {
    // return (this->x > other.x || this->y > other.y || this->z > other.z);
// }

// bool Vector3f::operator<(const Vector3f &other)
// {
    // return (this->x < other.x || this->y < other.y || this->z < other.z);
// }

// bool Vector3f::operator<=(const Vector3f &other)
// {
    // return (this->x <= other.x || this->y <= other.y || this->z <= other.z);
// }

// float Vector3f::Length()
// {
    // return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
// }

// Vector3f &Vector3f::Normalize()
// {
    // return (*this /= this->Length());
// }

// float Vector3f::Dot(const Vector3f& vec1, const Vector3f& vec2)
// {
    // return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
// }

// Vector3f Vector3f::Cross(const Vector3f& vec1, const Vector3f& vec2)
// {
    // return Vector3f(
        // vec1.y * vec2.z - vec1.z * vec2.y,
        // vec1.z * vec2.x - vec1.x * vec2.z,
        // vec1.x * vec2.y * vec1.y * vec2.x);
// }

// void Vector3f::Print()
// {
    // printf("%.2f %.2f %.2f\n", this->x, this->y, this->z);
// }

ATOM_END