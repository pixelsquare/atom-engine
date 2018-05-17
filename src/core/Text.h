/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/
#ifndef __ATOM_TEXT_H__
#define __ATOM_TEXT_H__

#include "PlatformMacros.h"

ATOM_BEGIN

enum FontSize 
{
	SMALL_FONT,
	MEDIUM_FONT,
	LARGE_FONT
};

class ATOMAPI Text
{
public:
    static void AddText2D(float x, float y, char* string, FontSize type);
    static void AddText3D(float x, float y, float z, char* string, FontSize type);

private:
    static void* FontStyle(FontSize type);

protected:
};

ATOM_END

#endif // __ATOM_TEXT_H__