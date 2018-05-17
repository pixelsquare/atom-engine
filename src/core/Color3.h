/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_COLOR3_H_
#define _ATOM_COLOR3_H_

#include "PlatformMacros.h"

ATOM_BEGIN

class ATOMAPI Color3 
{
public:
	Color3();
	Color3(float red, float green, float blue);
	~Color3();

	Color3 &operator=(const Color3 &rhs);

	Color3 &operator+=(const Color3 &rhs);
	Color3 operator+(const Color3 &op);

	Color3 &operator-=(const Color3 &rhs);
	Color3 operator-(const Color3 &op);

	Color3 &operator*=(const float scalar);
	Color3 operator*(const float scalar);

	Color3 &operator*=(const Color3 &rhs);
	Color3 operator*(const Color3 &op);

	Color3 &operator/=(const float scalar);
	Color3 operator/(const float scalar);

	Color3 &operator/=(const Color3 &rhs);
	Color3 operator/(const Color3 &op);

	bool operator==(const Color3 &other);
	bool operator!=(const Color3 &other);

	bool operator>(const Color3 &other);
	bool operator>=(const Color3 &other);

	bool operator<(const Color3 &other);
	bool operator<=(const Color3 &other);

	void Print();

	static Color3 RED;		static Color3 YELLOW;	
	static Color3 GREEN;	static Color3 CYAN;
	static Color3 BLUE;		static Color3 MAGENTA;
	static Color3 WHITE;	static Color3 GRAY;
    static Color3 BLACK;

	float r;
	float g;
	float b;

private:
protected:
};

ATOM_END

#endif // _ATOM_COLOR3_H_