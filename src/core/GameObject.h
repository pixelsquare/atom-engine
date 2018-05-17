/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_GAMEOBJECT_H_
#define _ATOM_GAMEOBJECT_H_

#include "PlatformMacros.h"
#include "Physics.h"
#include "Color3.h"
#include "Vector3f.h"

ATOM_BEGIN

// Object Property
class ATOMAPI ObjectProperty
{
public:
	std::vector<Vector3f*> vec;

	Vector3f* vertices;
	Vector3f* normals;
	Vector3f* faces;
	Color3* colors;
	char* fileName;

	long connectedTris;
	long connectedPts;

	int indx;

	Vector3f GetNormal(Vector3f coord1, Vector3f coord2, Vector3f coord3);

private:
protected:
};

// ObjectLoader
class ATOMAPI ObjectLoader : public ObjectProperty
{
public:
	ObjectLoader();

	ObjectLoader& operator=(const ObjectLoader& rhs);

	void LoadObject(const char* filename);
	void DrawObject();

private:
protected:
};

extern ObjectLoader asset[8];

// GameObject
class ATOMAPI GameObject : public Physics
{
public:
    GameObject();
    ~GameObject();

    void SetActiveGameObject(bool active);
    void SetName(char* name);

    void DrawPrimitive(int type);
    void InitializeObject(char* filename);
    void DrawObject();

    virtual void SetColor(Color3 Color);
    virtual void SetColor(float Red, float Green, float Blue);

    virtual void SetScale(Vector3f scale);
    virtual void SetScale(float scaleX, float scaleY, float scaleZ);

private:
    char* name;
    bool isActive;
    bool initModel;
    Vector3f tmpScale;
    Color3 tmpColor;

    ObjectLoader* objLoader;
    ObjectLoader loadedObj;

protected:

};

ATOM_END

#endif // _ATOM_GAMEOBJECT_H_