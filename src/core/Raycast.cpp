/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#include "Raycast.h"

ATOM_BEGIN

//Vector3f view, horiz, vert, resultDir;
//Vector3f renderDir, renderDirNormalized, finalResultPos, finalResultDir;
//int counter;
//
//int i;
//int rayLength;
//	
//bool init = false;
//Vector3f* renderPoints = 0;
//bool detectOnce = false;

void Raycast::RayPick(float x, float y) 
{
	//Vector3f resultPos, newV, newH, newView;
	//float radiansFOV, verticalLength, horizontalLength;
	//counter = 0;

	//view = atomCamera.lookAt - atomCamera.position;
	//view.Normalize();

	//horiz = horiz.Cross(view, atomCamera.up);
	//horiz.Normalize();

	//vert = vert.Cross(horiz, view);
	//vert.Normalize();

	//radiansFOV = (float)(45.0f * 3.14f / 180.0f);

	//verticalLength = (float)(tan(radiansFOV / 2) * 0.1f);
	//float aspectRatio = (float) atomWindow.width / (float) atomWindow.height;
	//horizontalLength = verticalLength * aspectRatio;

	//vert *= verticalLength;
	//horiz *= horizontalLength;

	//x = (float)(x - (atomWindow.width / 2.0f));
	//y = (float)(y - (atomWindow.height / 2.0f));

	//x = (float)(x / (atomWindow.width / 2.0f));
	//y = (float)(y / (atomWindow.height / 2.0f));

	//newH = horiz;
	//newH *= x;

	//newV = vert;
	//newV *= y;

	//newView = view;
	//newView *= 0.1f;

	//resultPos += atomCamera.position;
	//resultPos += newView;
	//resultPos += newH;
	//resultPos += newV;
	//finalResultPos = resultPos;

	//resultDir = resultPos - atomCamera.position;
	//finalResultDir = resultDir;

	//renderDir = finalResultDir;
	//renderDir.Normalize();

	//init = true;
}

void Raycast::DrawRay(int length, Vector3f &vec) 
{
	//if(init) 
 //   {
	//	renderPoints = new Vector3f[length];
	//	renderPoints[0] = finalResultPos;
	//	rayLength = length;
	//	detectOnce = false;
	//	init = false;
	//}

	//if(renderPoints == NULL)
 //   {
 //       return;
 //   }

	//while(counter < length) 
 //   {
 //       if(counter == length)
 //       {
 //           break;
 //       }

 //       if(counter > 0)
 //       {
 //           renderPoints[counter] = renderPoints[counter - 1] + Vector3f(renderDir.x, -renderDir.y, renderDir.z);
 //       }

	//	counter++;
	//}

	//vec = renderPoints[length - 1];
}
	
bool Raycast::CheckRayHit(GameObject &object) 
{
    //if(renderPoints == NULL)
    //{
    //    return false;
    //}

    //if(detectOnce)
    //{
    //    return false;
    //}

    //if(i < rayLength)
    //{
    //    i++;
    //}
    //else
    //{
    //    i = 1;
    //}

	//if(renderPoints[i] != Vector3f::ZERO) 
 //   {
	//
	//	bool xHasNotCollided =
	//		renderPoints[i].x - 0.1f >
	//		object.GetPosition().x + object.colliderOffset.x ||
	//		renderPoints[i].x + 0.1f <
	//		object.GetPosition().x - object.colliderOffset.x;

	//	bool yHasNotCollided = 
	//		renderPoints[i].y - 0.1f >
	//		object.GetPosition().y + object.colliderOffset.y ||
	//		renderPoints[i].y + 0.1f <
	//		object.GetPosition().y - object.colliderOffset.y;

	//	bool zHasNotCollided = 
	//		renderPoints[i].z - 0.1f >
	//		object.GetPosition().z + object.colliderOffset.z ||
	//		renderPoints[i].z + 0.1f<
	//		object.GetPosition().z - object.colliderOffset.z;

	//	if(xHasNotCollided || yHasNotCollided || zHasNotCollided)
	//		detectOnce = false;
	//	else
	//		detectOnce = true;

	//}

	//return detectOnce;

    return false;
}

ATOM_END