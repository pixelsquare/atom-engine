/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Input.h"
#include "PlatformGL.h"

ATOM_BEGIN

void (*mousePtr)(int x, int y);
void (*mouseDownPtr)(int x, int y);
void (*mousePassivePtr)(int x, int y);

bool keyHold[256];
bool mouseButton[3];

bool Input::GetKey(unsigned char key) 
{
	return keyHold[key];
}

bool Input::GetSpecialKey(SpecialKey type) 
{
	return specialKeyHold[static_cast<int>(type)];
}

bool Input::GetKeyDown(unsigned char key) 
{
	return keyDown[key];
}

/* Private Functions */
void atomOnKeyDown(unsigned char key, int x, int y) 
{
	keyHold[key] = true;
	specialKeyHold[key] = false;
	inputKey = key;

    if(!isPressed)
    {
        keyDown[key] = true;
    }

	if(key == 27) 
    {
		exit(1);
	}
}

void atomOnKeyHold(unsigned char key, int x, int y) 
{
	keyHold[key] = false;
	specialKeyHold[key] = false;

	isPressed = false;
	specialPressed = false;
}

void atomOnSpecialKey(int key, int x, int y) 
{
    if(!specialPressed)
    {
        specialKeyHold[key] = true;
    }

	inputSpecialKey = key;
}

void atomOnMouseButton(int button, int state, int x, int y) 
{
	bool pressed = (state == GLUT_DOWN) ? true : false;

	switch(button) 
    {
	    case GLUT_LEFT_BUTTON:
        {
            //editMode.mouseClick[0] = pressed;
            mouseButton[0] = pressed;
            break;
        }
	    case GLUT_MIDDLE_BUTTON:
        {
		    //editMode.mouseClick[1] = pressed;
		    mouseButton[1] = pressed;
		    break;
        }
	    case GLUT_RIGHT_BUTTON:
        {
		    //editMode.mouseClick[2] = pressed;
		    mouseButton[2] = pressed;
		    break;
        }
	    default:
		    break;
	}

	if(pressed && mouseDownPtr != NULL) 
    {
		mouseDownPtr(x, y);
    }

    //if(pressed)
    //{
    //    RayPick(x, y);
    //}

	//if(inEditMode) 
 //   {
	//	editMode.lastX = x;
	//	editMode.lastY = y;
	//}
}

void atomOnMouseMove(int x, int y) 
{
	if(mousePtr != NULL) 
    {
        mousePtr(x, y);
    }

	//if(inEditMode) 
 //   {
	//	int diffX = x - editMode.lastX;
	//	int diffY = y - editMode.lastY;

	//	editMode.lastX = x;
	//	editMode.lastY = y;

	//	if(editMode.mouseClick[0]) 
 //       {
	//		editMode.rotation.x += (float) 0.5f * diffY;
	//		editMode.rotation.y += (float) 0.5f * diffX;
	//	}
	//	if(editMode.mouseClick[1]) 
 //       {
	//		editMode.position.z -= (float) 0.5f * diffX;
	//	}
	//	if(editMode.mouseClick[2]) 
 //       {
	//		editMode.position.x += (float) 0.05f * diffX;
	//		editMode.position.y -= (float) 0.05f * diffY;
	//	}
	//}
}

void atomOnPassiveMouse(int x, int y) 
{
	if(mousePassivePtr != NULL) 
    {
        mousePassivePtr(x, y);
    }
}
/* End of Private functions*/

void atomMouseFunc( void(*func)(int x, int y) ) 
{
	mousePtr = func;
}

void atomMouseDownFunc( void(*func)(int x, int y) ) 
{
	mouseDownPtr = func;
}

void atomPassiveMouseFunc( void(*func)(int x, int y) ) 
{
	mousePassivePtr = func;
}

bool GetMouseDown(MouseType type) 
{
	return mouseButton[static_cast<int>(type)];
}

ATOM_END