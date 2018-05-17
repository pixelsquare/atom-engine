/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_TIME_H_
#define _ATOM_TIME_H_

#include "PlatformMacros.h"

ATOM_BEGIN

class ATOMAPI Time 
{
public:
	Time();
	~Time();

	float LocalElapsedTime();
	float LocalDeltaTime();
	void LocalReset();

	static float GetFPS();
	static float GetDeltaTime();
	static float GetElapsedTime();
	static void Reset();

private:
	float previousTime;
	float presentTime;
	float startTime;

	float dt;
	float elapsedTime;

protected:
};

ATOM_END

#endif // _ATOM_TIME_H_