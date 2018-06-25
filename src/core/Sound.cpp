/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Sound.h"

ATOM_BEGIN

Sound::Sound()
    : mute(false)
    , loop(false)
{
}

Sound::~Sound()
{
    mute = false;
    loop = false;
}

// FIX: prevent creating global instance
Sound* sound = new Sound;

#if TARGET_PLATFORM == PLATFORM_WIN32
void Sound::Play(LPCTSTR name)
#else
void Sound::Play(std::string name)
#endif
{
	if(!sound->mute) 
    {
        if(sound->loop)
        {
            PlaySound(name, NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        }
        else
        {
            PlaySound(name, NULL, SND_ASYNC | SND_FILENAME);
        }
	}
}

void Sound::Stop() 
{
	PlaySound(NULL, 0, 0);
}

void Sound::Loop(bool loop) 
{
	sound->loop = loop;
}

void Sound::Mute(bool mute) 
{
	sound->mute = mute;
}

ATOM_END