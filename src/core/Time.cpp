/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Time.h"
#include "PlatformGL.h"

ATOM_BEGIN

// FIX: Prevent global object creation
Time *gameTime = new Time;

float Time::GetFPS() 
{
	return 1.0f / gameTime->LocalDeltaTime();
}

float Time::GetDeltaTime() 
{
	return gameTime->LocalDeltaTime();
}

float Time::GetElapsedTime() 
{
	return gameTime->LocalElapsedTime();
}

void Time::Reset() 
{
	gameTime->LocalReset();
}

Time::Time()
: presentTime(0.0f)
, previousTime(0.0f)
, dt(0.0f)
, elapsedTime(0.0f)
{
	this->startTime = glutGet(GLUT_ELAPSED_TIME);
}

Time::~Time() 
{
	this->presentTime = 0.0f;
	this->previousTime = 0.0f;
	this->startTime = 0.0f;
	this->dt = 0.0f;
	this->elapsedTime = 0.0f;
}

/* returns the time elapsed */
float Time::LocalElapsedTime() 
{
	float timeNow = glutGet(GLUT_ELAPSED_TIME);
	this->elapsedTime = timeNow - this->startTime;
	this->elapsedTime /= 1000.0f;
	return this->elapsedTime;
}

/* returnds the delta time */
float Time::LocalDeltaTime() 
{
	this->presentTime = glutGet(GLUT_ELAPSED_TIME);
	this->dt = this->presentTime - this->previousTime;
	this->previousTime = this->presentTime;

	this->dt /= 1000.0f;
	return this->dt;
}

void Time::LocalReset() 
{
	this->startTime = glutGet(GLUT_ELAPSED_TIME);
}

ATOM_END