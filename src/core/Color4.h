/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_COLOR4_H_
#define _ATOM_COLOR4_H_

#include "PlatformMacros.h"

ATOM_BEGIN

class ATOMAPI Color4
{
public:
	Color4();
	Color4(float red, float green, float blue, float alpha);
	~Color4();

	Color4 &operator=(const Color4 &rhs);

	Color4 &operator+=(const Color4 &rhs);
	Color4 operator+(const Color4 &op);

	Color4 &operator-=(const Color4 &rhs);
	Color4 operator-(const Color4 &op);

	Color4 &operator*=(const float scalar);
	Color4 operator*(const float scalar);

	Color4 &operator*=(const Color4 &rhs);
	Color4 operator*(const Color4 &op);

	Color4 &operator/=(const float scalar);
	Color4 operator/(const float scalar);

	Color4 &operator/=(const Color4 &rhs);
	Color4 operator/(const Color4 &op);

	bool operator==(const Color4 &other);
	bool operator!=(const Color4 &other);

	bool operator>(const Color4 &other);
	bool operator>=(const Color4 &other);

	bool operator<(const Color4 &other);
	bool operator<=(const Color4 &other);

	void Print();

	static Color4 RED;		static Color4 YELLOW;	
	static Color4 GREEN;	static Color4 CYAN;
	static Color4 BLUE;		static Color4 MAGENTA;
	static Color4 WHITE;	static Color4 GRAY;
    static Color4 BLACK;

	float r;
	float g;
	float b;
	float a;

private:
protected:
};

ATOM_END

#endif // _ATOM_COLOR4_H_