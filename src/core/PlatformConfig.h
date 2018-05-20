/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_PLATFORM_CONFIG_H_
#define _ATOM_PLATFORM_CONFIG_H_

#define PLATFORM_UNKNOWN    0x00
#define PLATFORM_WIN32      0x01

#define TARGET_PLATFORM     PLATFORM_UNKNOWN

#if defined(_WIN32) || defined(_WINDOWS)
    #undef TARGET_PLATFORM
    #define TARGET_PLATFORM PLATFORM_WIN32
#else
	#undef TARGET_PLATFORM
    #define TARGET_PLATFORM PLATFORM_WIN32
#endif

#if !TARGET_PLATFORM
    #error "Unable to identify target platform"
#endif // !TARGET_PLATFORM

#if TARGET_PLATFORM == PLATFORM_WIN32

#ifndef __MINGW32__
    #pragma warning (disable:4127)
#endif

#if defined(_WIN32) && defined(_WINDOWS)
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
#endif

#endif // TARGET_PLATFORM == PLATFORM_WIN32

#endif // _ATOM_PLATFORM_CONFIG_H_