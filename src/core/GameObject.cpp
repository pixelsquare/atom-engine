/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "GameObject.h"
#include "PlatformGL.h"

#include <iostream>
#include <fstream>
#include <string>

ATOM_BEGIN

#define POINTS_PER_VERTEX 3
#define TOTAL_FLOATS_IN_TRIANGLE 9
	
Vector3f ObjectProperty::GetNormal(Vector3f coord1, Vector3f coord2, Vector3f coord3) 
{
	Vector3f va; Vector3f vb; Vector3f vr; float val;
	va.x = coord1.x - coord2.x;
	va.y = coord1.y - coord2.y;
	va.z = coord1.z - coord2.z;

	vb.x = coord1.x - coord3.x;
	vb.y = coord1.y - coord3.y;
	vb.z = coord1.z - coord3.z;
	
	vr.x = va.y * vb.z - vb.y * va.z;
	vr.y = vb.x * va.z - va.x * vb.z;
	vr.z = va.x * vb.y - vb.x * va.y;

	val = sqrt(vr.x * vr.x + vr.y * vr.y + vr.z * vr.z);

	Vector3f norm;
	norm.x = vr.x / val;
	norm.y = vr.y / val;
	norm.z = vr.z / val;

	return norm;
}

// ObjectLoader

ObjectLoader::ObjectLoader() 
{ 
	this->indx = 0;
}

ObjectLoader &ObjectLoader::operator=(const ObjectLoader& rhs) 
{
	this->indx = rhs.indx;
	this->connectedTris = this->indx;

	this->vertices = new Vector3f[rhs.vec.size()];
	for(int i = 0; i < rhs.vec.size(); i++) 
    {
		this->vertices[i] = rhs.vertices[i];
	}

	this->faces = new Vector3f[this->indx];
	this->normals = new Vector3f[this->indx];
	this->colors = new Color3[this->indx];
	for(int i = 0; i < this->indx; i += 9) 
    {
		for(int j = 0; j < 3; j++) 
        {
			this->faces[i + j] = rhs.faces[i + j];
			this->normals[i + j] = rhs.normals[i + j];
			this->colors[i + j] = rhs.colors[i + j];
		}
	}

	return *this;
}

void ObjectLoader::LoadObject(const char* filename) 
{
	this->fileName = (char*)filename;
	std::cout << "Loading Primitive " << this->fileName << std::endl;
	std::string line;
	std::ifstream objFile(this->fileName);

	if(objFile.is_open()) 
    {
		objFile.seekg(0, std::ios::end);
		long fileSize = objFile.tellg();
		objFile.seekg(0, std::ios::beg);

		this->vertices = new Vector3f[fileSize];
		this->faces = new Vector3f[fileSize * sizeof(Vector3f*)];
		this->normals = new Vector3f[fileSize * sizeof(Vector3f*)];
		this->colors = new Color3[fileSize * sizeof(Vector3f*)];

		while(!objFile.eof()) 
        {
			getline(objFile, line);

			if(line.c_str()[0] == 'v') 
            {
				line[0] = ' ';
				sscanf(line.c_str(), "%f %f %f ",
					&this->vertices[this->connectedPts].x,
					&this->vertices[this->connectedPts].y,
					&this->vertices[this->connectedPts].z);


				vec.push_back(&vertices[this->connectedPts]);
				this->connectedPts++;
			}

			if(line.c_str()[0] == 'f') 
            {
				line[0] = ' ';

				int vertexNumber[4] = {0, 0, 0};
				sscanf(line.c_str(), "%i%i%i",
					&vertexNumber[0],
					&vertexNumber[1],
					&vertexNumber[2]);

				vertexNumber[0] -= 1;
				vertexNumber[1] -= 1;
				vertexNumber[2] -= 1;

				for(int i = 0; i < 3; i++) 
                {
					this->faces[indx + i] = this->vertices[vertexNumber[i]];
				}

				Vector3f coord1 = Vector3f(this->faces[indx].x, this->faces[indx].y, this->faces[indx].z);
				Vector3f coord2 = Vector3f(this->faces[indx + 1].x, this->faces[indx + 1].y, this->faces[indx + 1].z);
				Vector3f coord3 = Vector3f(this->faces[indx + 2].x, this->faces[indx + 2].y, this->faces[indx + 2].z);
				Vector3f normal = this->GetNormal(coord1, coord2, coord3);

				for(int i = 0; i < 3; i++) 
                {
					this->normals[indx + i] = normal;
				}

				for(int i = 0; i < 3; i++) 
                {
					this->colors[indx + i] = Color3::WHITE;
				}

				indx += 9;
				this->connectedTris += 9;
			}
		}

		objFile.close();
	}
}

void ObjectLoader::DrawObject() 
{
	glPushMatrix();
		glVertexPointer(3,GL_FLOAT,	0, this->faces);
		glNormalPointer(GL_FLOAT, 0, this->normals);
		glColorPointer(3, GL_FLOAT, 0, this->colors);

		glEnableClientState(GL_VERTEX_ARRAY);
 		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glDrawArrays(GL_TRIANGLES, 0, this->connectedTris);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	glPopMatrix();
}

ObjectLoader asset[8];

// GameObject

GameObject::GameObject() 
{ 
	this->name = new char;
	this->isActive = true;
	this->initModel = false;
	this->tmpScale = Vector3f::ONE;
	this->tmpColor = Color3::WHITE;
	this->objLoader = new ObjectLoader();
		
}

GameObject::~GameObject() { }

void GameObject::SetActiveGameObject(bool active) 
{
	this->isActive = active;
}

void GameObject::SetName(char* nme) 
{
	this->name = nme;
}

void GameObject::DrawPrimitive(int type) 
{
	if(!this->initModel) 
    {
        switch(type)
        {
            case 50:
            {
                *this->objLoader = asset[0];
                break;
            }
            case 51:
            {
                *this->objLoader = asset[1];
                break;
            }
            case 52:
            {
                *this->objLoader = asset[2];
                break;
            }
            case 53:
            {
                *this->objLoader = asset[3];
                break;
            }
            case 54:
            {
                *this->objLoader = asset[4];
                break;
            }
            case 55:
            {
                *this->objLoader = asset[5];
                break;
            }
            case 56:
            {
                *this->objLoader = asset[6];
                break;
            }
            case 57:
            {
                *this->objLoader = asset[7];
                break;
            }
        }

		this->initModel = true;
		this->SetScale(tmpScale);
		this->SetColor(tmpColor);
	}

	this->ApplyPhysics();
	this->DrawCollider();

	glPushMatrix();
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glRotatef(this->angleRot, this->axis.x, this->axis.y, this->axis.z);

    if(this->isActive)
    {
        this->objLoader->DrawObject();
    }

	glPopMatrix();
}

void GameObject::InitializeObject(char* filename) 
{
	if(!this->initModel) 
    {
		this->loadedObj.LoadObject(filename);

		this->initModel = true;
		this->SetScale(tmpScale);
		this->SetColor(tmpColor);
	}
}

void GameObject::DrawObject() 
{
	this->ApplyPhysics();
	this->DrawCollider();

	glPushMatrix();
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glRotatef(this->angleRot, this->axis.x, this->axis.y, this->axis.z);

    if(this->isActive)
    {
        this->loadedObj.DrawObject();
    }

	glPopMatrix();
}

void GameObject::SetColor(Color3 col) 
{
	if(!this->initModel) 
    {
		tmpColor = col;
	}

	if(this->color != col && this->objLoader->indx != 0) 
    {
		int tmpNum = this->objLoader->indx - 9;
		for(int i = 0; i < this->objLoader->indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->color = col;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->objLoader->colors[i + j] = col;
			}
		}
	}

	if(this->color != col && this->loadedObj.indx != 0) 
    {
		int tmpNum = this->loadedObj.indx - 9;
		for(int i = 0; i < this->loadedObj.indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->color = col;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->loadedObj.colors[i + j] = col;
			}
		}
	}
}

void GameObject::SetColor(float red, float green, float blue) 
{
	Color3 col = Color3(red, green, blue);

	if(!this->initModel) 
    {
		tmpColor = col;
	}

	if(this->color != col && this->objLoader->indx != 0) 
    {
		int tmpNum = this->objLoader->indx - 9;
		for(int i = 0; i < this->objLoader->indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->color = col;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->objLoader->colors[i + j] = col;
			}
		}
	}

	if(this->color != col && this->loadedObj.indx != 0) 
    {
		int tmpNum = this->loadedObj.indx - 9;
		for(int i = 0; i < this->loadedObj.indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->color = col;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->loadedObj.colors[i + j] = col;
			}
		}
	}
}

void GameObject::SetScale(Vector3f scl)
{
	if(!this->initModel) 
    {
		tmpScale = scl;
	}

	if(this->scale != scl && this->objLoader->indx != 0) 
    {
		int tmpNum = this->objLoader->indx - 9;
		for(int i = 0; i < this->objLoader->indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->scale = scl;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->objLoader->faces[i + j] *= scl;
			}
		}
	}

	if(this->scale != scl && this->loadedObj.indx != 0) 
    {
		int tmpNum = this->loadedObj.indx - 9;
		for(int i = 0; i < this->loadedObj.indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->scale = scl;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->objLoader->faces[i + j] *= scl;
			}
		}
	}
}

void GameObject::SetScale(float sclX, float sclY, float sclZ) 
{
	Vector3f scl = Vector3f(sclX, sclY, sclZ);

	if(!this->initModel) 
    {
		tmpScale = scl;
	}

	if(this->scale != scl && this->objLoader->indx != 0)
    {
		int tmpNum = this->objLoader->indx - 9;
		for(int i = 0; i < this->objLoader->indx; i += 9) 
        {
            if(i == tmpNum)
            {
                this->scale = scl;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->objLoader->faces[i + j] *= scl;
			}
		}
	}

	if(this->scale != scl && this->loadedObj.indx != 0) 
    {
		int tmpNum = this->loadedObj.indx - 9;
		for(int i = 0; i < this->loadedObj.indx; i += 9)
        {
            if(i == tmpNum)
            {
                this->scale = scl;
            }

			for(int j = 0; j < 3; j++) 
            {
				this->objLoader->faces[i + j] *= scl;
			}
		}
	}
}

ATOM_END