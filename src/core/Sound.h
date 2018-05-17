/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef __ATOM_SOUND_H__
#define __ATOM_SOUND_H__

#include "PlatformMacros.h"
#include "StdC.h"

ATOM_BEGIN

class ATOMAPI Sound
{
public:
	Sound();
    ~Sound();

#if TARGET_PLATFORM == PLATFORM_WIN32
	static void Play(LPCTSTR name);
#else
    static void Play(string name);
#endif

	static void Stop();
	static void Loop(bool loop);
	static void Mute(bool mute);

private:
	bool mute;
	bool loop;

protected:
};

ATOM_END

#endif // __ATOM_SOUND_H__