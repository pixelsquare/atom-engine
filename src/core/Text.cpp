/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Text.h"
#include "StdC.h"
#include "PlatformGL.h"

ATOM_BEGIN

char text[1000];

void* Text::FontStyle(FontSize type) 
{
	void* font = GLUT_BITMAP_HELVETICA_10;

	switch(type) 
    {
	    case SMALL_FONT:
        {
            font = GLUT_BITMAP_HELVETICA_10;
            break;
        }
	    case MEDIUM_FONT:
        {
		    font = GLUT_BITMAP_HELVETICA_12;
		    break;
        }
	    case LARGE_FONT:
        {
		    font = GLUT_BITMAP_HELVETICA_18;
		    break;
	    }
    }

	return font;
}

void Text::AddText2D(float x, float y, char* string, FontSize type) 
{
	void* font = FontStyle(type);
	sprintf(text, string);
	char* stringPtr;
	glRasterPos2f(x, y);
    for(stringPtr = string; *stringPtr != '\0'; stringPtr++)
    {
        glutBitmapCharacter(font, *stringPtr);
    }
}

void Text::AddText3D(float x, float y, float z, char* string, FontSize type) 
{
	void* font = FontStyle(type);
	sprintf(text, string);
	char* stringPtr;
	glRasterPos3f(x, y, z);
    for(stringPtr = string; *stringPtr != '\0'; stringPtr++)
    {
        glutBitmapCharacter(font, *stringPtr);
    }
}

 ATOM_END