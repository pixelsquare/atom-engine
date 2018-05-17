/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_MATHF_H_
#define _ATOM_MATHF_H_

#include "PlatformMacros.h"

ATOM_BEGIN

class Mathf
{
public:
	static float Sqrtf(float value);
	static float PI();

	static double Abs(double value);
	static double Sin(double value);
	static double Cos(double value);
	static double Tan(double value);

	static double Asin(double value);
	static double Acos(double value);
	static double Atan(double value);

	static double Exp(double value);
	static double Log(double value);
	static double Pow(double val1, double val2);

	static double Ceil(double value);
	static double Floor(double value);
	static double Round(double value, double placeValue);
private:
protected:
};

ATOM_END

#endif // _ATOM_MATHF_H_