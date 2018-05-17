/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_INPUT_H__
#define _ATOM_INPUT_H__

#include "PlatformMacros.h"

ATOM_BEGIN

/* Atom engine pre-made special keys */
enum SpecialKey
{
    AE_F1 = 1, AE_F2 = 2, AE_F3 = 3, AE_F4 = 4, AE_F5 = 5, AE_F6 = 6,
    AE_F7 = 7, AE_F8 = 8, AE_F9 = 9, AE_F10 = 10, AE_F11 = 11, AE_F12 = 12,
    AE_LEFT = 100, AE_UP = 101, AE_RIGHT = 102, AE_DOWN = 103, AE_PAGEUP = 104,
    AE_PAGEDOWN = 105, AE_HOME = 106, AE_END = 107, AE_INSERT = 108

};

/* Options for mouse clicking */
enum MouseType
{
    Left = 0,
    Middle = 1,
    Right = 2
};

class ATOMAPI Input
{
public:
    static bool GetKey(unsigned char key);
    static bool GetSpecialKey(SpecialKey type);
    static bool GetKeyDown(unsigned char key);
    static bool GetMouseDown(MouseType type);

private:
protected:
};

static bool keyDown[256];
static unsigned char inputKey;
static bool isPressed;

static bool specialKeyHold[21];
static int inputSpecialKey;
static bool specialPressed;

/* Private functions */
void atomOnKeyDown(unsigned char key, int x, int y);
void atomOnKeyHold(unsigned char key, int x, int y);
void atomOnSpecialKey(int key, int x, int y);
void atomOnMouseButton(int button, int state, int x, int y);
void atomOnMouseMove(int x, int y);
void atomOnPassiveMouse(int x, int y);

void atomMouseFunc(void(*func)(int x, int y));
void atomMouseDownFunc(void(*func)(int x, int y));
void atomPassiveMouseFunc(void(*func)(int x, int y));

ATOM_END

#endif // _ATOM_INPUT_H__