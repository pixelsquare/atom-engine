/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Color4.h"
#include <stdio.h>

ATOM_BEGIN

Color4 Color4::RED		= Color4(1.0f, 0.0f, 0.0f, 1.0f);
Color4 Color4::GREEN	= Color4(0.0f, 1.0f, 0.0f, 1.0f);
Color4 Color4::BLUE		= Color4(0.0f, 0.0f, 1.0f, 1.0f);
Color4 Color4::WHITE	= Color4(1.0f, 1.0f, 1.0f, 1.0f);
Color4 Color4::YELLOW	= Color4(1.0f, 1.0f, 0.0f, 1.0f);
Color4 Color4::CYAN		= Color4(0.0f, 1.0f, 1.0f, 1.0f);
Color4 Color4::MAGENTA	= Color4(1.0f, 0.0f, 1.0f, 1.0f);
Color4 Color4::GRAY		= Color4(0.5f, 0.5f, 0.5f, 1.0f);
Color4 Color4::BLACK    = Color4(0.0f, 0.0f, 0.0f, 0.0f);

Color4::Color4()
    : r(0.0f)
    , g(0.0f)
    , b(0.0f)
    , a(0.0f)
{
}

Color4::Color4(float red, float green, float blue, float alpha)
{
    this->r = red;
    this->g = green;
    this->b = blue;
    this->a = alpha;
}

Color4::~Color4() {}

Color4 &Color4::operator=(const Color4 &rhs)
{
    this->r = rhs.r;
    this->g = rhs.g;
    this->b = rhs.b;
    this->a = rhs.a;

    return *this;
}

Color4 &Color4::operator+=(const Color4 &rhs)
{
    this->r += rhs.r;
    this->g += rhs.g;
    this->b += rhs.b;
    this->a += rhs.a;

    return *this;
}

Color4 Color4::operator+(const Color4 &op)
{
    Color4 rhs;
    rhs.r = this->r + op.r;
    rhs.g = this->g + op.g;
    rhs.b = this->b + op.b;
    rhs.a = this->a + op.a;

    return rhs;
}

Color4 &Color4::operator-=(const Color4 &rhs)
{
    this->r -= rhs.r;
    this->g -= rhs.g;
    this->b -= rhs.b;
    this->a -= rhs.a;

    return *this;
}

Color4 Color4::operator-(const Color4 &op)
{
    Color4 rhs;
    rhs.r = this->r - op.b;
    rhs.g = this->g - op.g;
    rhs.b = this->b - op.r;
    rhs.a = this->a - op.a;

    return rhs;
}

Color4 &Color4::operator*=(const float scalar)
{
    this->r *= scalar;
    this->g *= scalar;
    this->b *= scalar;
    this->a *= scalar;

    return *this;
}

Color4 Color4::operator*(const float scalar)
{
    Color4 rhs;
    rhs.r = this->r * scalar;
    rhs.g = this->g * scalar;
    rhs.b = this->b * scalar;
    rhs.a = this->a * scalar;

    return rhs;
}

Color4 &Color4::operator*=(const Color4 &rhs)
{
    this->r *= rhs.r;
    this->g *= rhs.g;
    this->b *= rhs.b;
    this->a *= rhs.a;

    return *this;
}

Color4 Color4::operator*(const Color4 &op)
{
    Color4 rhs;
    rhs.r = this->r * op.r;
    rhs.g = this->g * op.g;
    rhs.b = this->b * op.b;
    rhs.a = this->a * op.a;

    return rhs;
}

Color4 &Color4::operator/=(const float scalar)
{
    this->r /= scalar;
    this->g /= scalar;
    this->b /= scalar;
    this->a /= scalar;

    return *this;
}

Color4 Color4::operator/(const float scalar)
{
    Color4 rhs;
    rhs.r = this->r / scalar;
    rhs.g = this->g / scalar;
    rhs.b = this->b / scalar;
    rhs.a = this->a / scalar;

    return rhs;
}

Color4 &Color4::operator/=(const Color4 &rhs)
{
    this->r /= rhs.r;
    this->g /= rhs.g;
    this->b /= rhs.b;
    this->a /= rhs.a;

    return *this;
}

Color4 Color4::operator/(const Color4 &op)
{
    Color4 rhs;
    rhs.r = this->r / op.r;
    rhs.g = this->g / op.g;
    rhs.b = this->b / op.b;
    rhs.a = this->a / op.a;

    return rhs;
}

bool Color4::operator==(const Color4 &other)
{
    return (this->r == other.r && this->g == other.g && this->b == other.b && this->a == other.a);
}

bool Color4::operator!=(const Color4 &other)
{
    return (this->r != other.r || this->g != other.g || this->b != other.b || this->a != other.a);
}

bool Color4::operator>(const Color4 &other)
{
    return (this->r > other.r || this->g > other.g || this->b > other.b || this->a > other.a);
}

bool Color4::operator>=(const Color4 &other)
{
    return (this->r > other.r || this->g > other.g || this->b > other.b || this->a > other.a);
}

bool Color4::operator<(const Color4 &other)
{
    return (this->r < other.r || this->g < other.g || this->b < other.b || this->a < other.a);
}

bool Color4::operator<=(const Color4 &other)
{
    return (this->r <= other.r || this->g <= other.g || this->b <= other.b || this->a <= other.a);
}

void Color4::Print()
{
    printf("Color4 = (%.1f %.1f %.1f %.1f)\n", this->r, this->g, this->b, this->a);
}

ATOM_END