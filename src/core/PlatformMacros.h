/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_PLATFORM_MACROS_H_
#define _ATOM_PLATFORM_MACROS_H_

#include "PlatformConfig.h"
#include "PlatformDefine.h"

#ifdef __cplusplus
    #define ATOM_BEGIN  namespace AtomEngine {
    #define ATOM_END    }
    #define USING_ATOM  using namespace AtomEngine;
    #define NS_ATOM     ::AtomEngine
#else
    #define ATOM_BEGIN
    #define ATOM_END
    #define USING_ATOM
    #define NS_ATOM
#endif

#endif // _ATOM_PLATFORM_MACROS_H_