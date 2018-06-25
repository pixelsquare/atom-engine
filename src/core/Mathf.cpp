/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Mathf.h"

ATOM_BEGIN

float Mathf::Sqrtf(float value) 
{
	return sqrt(value);
}

float Mathf::PI() {
	return 3.14159265359f;
}

double Mathf::Abs(double value) 
{
	return fabs(value);
}

double Mathf::Sin(double value) 
{
	return sin(value);
}

double Mathf::Cos(double value) 
{
	return cos(value);
}

double Mathf::Tan(double value)
{
    return tan(value);
}

double Mathf::Asin(double value) 
{
	return asin(value);
}

double Mathf::Acos(double value) 
{
	return acos(value);
}

double Mathf::Atan(double value) 
{
	return atan(value);
}

double Mathf::Exp(double value) 
{
	return exp(value);
}

double Mathf::Log(double value) 
{
	return log(value);
}

double Mathf::Pow(double val1, double val2) 
{
	return pow(val1, val2);
}

double Mathf::Ceil(double value) 
{
	return ceil(value);
}

double Mathf::Floor(double value) 
{
	return floor(value);
}

double Mathf::Round(double value, double placeValue) 
{
	return Mathf::Floor(value * placeValue + 0.5f) / placeValue;
}

ATOM_END