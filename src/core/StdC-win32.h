/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_STDC_WIN32_H_
#define _ATOM_STDC_WIN32_H_

#include "PlatformMacros.h"

#if TARGET_PLATFORM == PLATFORM_WIN32

#if defined(_WIN32) && defined(WINDOWS)
#include <BaseTsd.h>
#endif

//#ifndef __SSIZE_T
//#define __SSIZE_T
//typedef SSIZE_T ssize_t;
//#endif // __SSIZE_T

#include <float.h>

// for math.h on win32 platform
#ifndef __MINGW32__

#if !defined(_USE_MATH_DEFINES)
#define _USE_MATH_DEFINES       // make M_PI can be use
#endif

#endif // __MINGW32__

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#if defined(_WIN32) && defined(WINDOWS)
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#include <Windows.h>
#include <MMSystem.h>
#endif

#ifndef M_PI
#define M_PI      3.14159265358
#endif

#ifndef M_PI_2
#define M_PI_2    1.57079632679
#endif

// for MIN MAX and sys/time.h on win32 platform
#ifdef __MINGW32__
#include <sys/time.h>
#endif // __MINGW32__

#if defined(_WIN32) && defined(WINDOWS)
#if _MSC_VER >= 1600 || defined(__MINGW32__)
#include <stdint.h>
#else
#include "platform/win32/compat/stdint.h"
#endif
#endif


#endif // TARGET_PLATFORM == PLATFORM_WIN32

#endif // _ATOM_STDC_WIN32_H_