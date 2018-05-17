/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Color3.h"

ATOM_BEGIN

Color3 Color3::RED		= Color3(1.0f, 0.0f, 0.0f);
Color3 Color3::GREEN	= Color3(0.0f, 1.0f, 0.0f);
Color3 Color3::BLUE		= Color3(0.0f, 0.0f, 1.0f);
Color3 Color3::WHITE	= Color3(1.0f, 1.0f, 1.0f);
Color3 Color3::YELLOW	= Color3(1.0f, 1.0f, 0.0f);
Color3 Color3::CYAN		= Color3(0.0f, 1.0f, 1.0f);
Color3 Color3::MAGENTA	= Color3(1.0f, 0.0f, 1.0f);
Color3 Color3::GRAY		= Color3(0.5f, 0.5f, 0.5f);
Color3 Color3::BLACK    = Color3(0.0f, 0.0f, 0.0f);

Color3::Color3()
: r(0.0f)
, g(0.0f)
, b(0.0f)
{
}

Color3::Color3(float red, float green, float blue)
{
    this->r = red;
    this->g = green;
    this->b = blue;
}

Color3::~Color3()
{
    r = 0.0f;
    g = 0.0f;
    b = 0.0f;
}

Color3 &Color3::operator=(const Color3 &rhs)
{
    this->r = rhs.r;
    this->g = rhs.g;
    this->b = rhs.b;

    return *this;
}

Color3 &Color3::operator+=(const Color3 &rhs)
{
    this->r += rhs.r;
    this->g += rhs.g;
    this->b += rhs.b;

    return *this;
}

Color3 Color3::operator+(const Color3 &op)
{
    Color3 rhs;
    rhs.r = this->r + op.r;
    rhs.g = this->g + op.g;
    rhs.b = this->b + op.b;

    return rhs;
}

Color3 &Color3::operator-=(const Color3 &rhs)
{
    this->r -= rhs.r;
    this->g -= rhs.g;
    this->b -= rhs.b;

    return *this;
}

Color3 Color3::operator-(const Color3 &op)
{
    Color3 rhs;
    rhs.r = this->r - op.b;
    rhs.g = this->g - op.g;
    rhs.b = this->b - op.r;

    return rhs;
}

Color3 &Color3::operator*=(const float scalar)
{
    this->r *= scalar;
    this->g *= scalar;
    this->b *= scalar;

    return *this;
}

Color3 Color3::operator*(const float scalar)
{
    Color3 rhs;
    rhs.r = this->r * scalar;
    rhs.g = this->g * scalar;
    rhs.b = this->b * scalar;

    return rhs;
}

Color3 &Color3::operator*=(const Color3 &rhs)
{
    this->r *= rhs.r;
    this->g *= rhs.g;
    this->b *= rhs.b;

    return *this;
}

Color3 Color3::operator*(const Color3 &op)
{
    Color3 rhs;
    rhs.r = this->r * op.r;
    rhs.g = this->g * op.g;
    rhs.b = this->b * op.b;

    return rhs;
}

Color3 &Color3::operator/=(const float scalar)
{
    this->r /= scalar;
    this->g /= scalar;
    this->b /= scalar;

    return *this;
}

Color3 Color3::operator/(const float scalar)
{
    Color3 rhs;
    rhs.r = this->r / scalar;
    rhs.g = this->g / scalar;
    rhs.b = this->b / scalar;

    return rhs;
}

Color3 &Color3::operator/=(const Color3 &rhs)
{
    this->r /= rhs.r;
    this->g /= rhs.g;
    this->b /= rhs.b;

    return *this;
}

Color3 Color3::operator/(const Color3 &op)
{
    Color3 rhs;
    rhs.r = this->r / op.r;
    rhs.g = this->g / op.g;
    rhs.b = this->b / op.b;

    return rhs;
}

bool Color3::operator==(const Color3 &other)
{
    return (this->r == other.r && this->g == other.g && this->b == other.b);
}

bool Color3::operator!=(const Color3 &other)
{
    return (this->r != other.r || this->g != other.g || this->b != other.b);
}

bool Color3::operator>(const Color3 &other)
{
    return (this->r > other.r || this->g > other.g || this->b > other.b);
}

bool Color3::operator>=(const Color3 &other)
{
    return (this->r > other.r || this->g > other.g || this->b > other.b);
}

bool Color3::operator<(const Color3 &other)
{
    return (this->r < other.r || this->g < other.g || this->b < other.b);
}

bool Color3::operator<=(const Color3 &other)
{
    return (this->r <= other.r || this->g <= other.g || this->b <= other.b);
}

void Color3::Print()
{
    printf("Color3 = (%.1f %.1f %.1f)\n", this->r, this->g, this->b);
}

ATOM_END