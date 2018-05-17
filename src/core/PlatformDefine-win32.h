/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_PLATFORM_DEFINE_WIN32_H_
#define _ATOM_PLATFORM_DEFINE_WIN32_H_

#ifdef __MINGW32__
    #include <string.h>
#endif

#if defined(ATOM_STATIC)
    #define ATOMAPI
#else
    #if defined(_USRDLL)
        #define ATOMAPI __declspec(dllexport)
    #else
        #define ATOMAPI __declspec(dllimport)
    #endif
#endif

#include <assert.h>
#include <vector>

#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else
        #define NULL ((void *)0)
    #endif
#endif

#endif // _ATOM_PLATFORM_DEFINE_WIN32_H_