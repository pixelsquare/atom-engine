/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_STDC_H_
#define _ATOM_STDC_H_

#include "PlatformMacros.h"

#if TARGET_PLATFORM == PLATFORM_WIN32
    #include "StdC-win32.h"
#elif TARGET_PLATFORM == PLATFORM_LINUX
    #include "StdC-linux.h"
#endif

#endif // _ATOM_STDC_H_