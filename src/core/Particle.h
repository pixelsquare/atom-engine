/*
* Copyright (C) 2012 PixelSquareLabs - All Rights Reserved
*
* Created: 06/05/2018
* Author:  Anthony Ganzon
* Email:   pixelsquarelabs@yahoo.com
*          pixelsquarelabs@gmail.com
*/

#ifndef _ATOM_PARTICLE_H_
#define _ATOM_PARTICLE_H_

#include "PlatformMacros.h"
#include "Physics.h"

ATOM_BEGIN

class Color3;
class Time;

/* class that holds particle subsystem */
class ATOMAPI Particle : public Physics 
{
public:
	Particle();
	~Particle();

	void SetActiveParticle(bool active);
	void SetAutoDestruct(bool active);

	void SetEnergy(int min, int max);
	void SetEmission(int min, int max);

	void SetEllipsoid(Vector3f ellipsoid);
	void SetEllipsoid(float x, float y, float z);

	void SetRandomVelocity(Vector3f randomVel);
	void SetRandomVelocity(float x, float y, float z);

	void SetColors(Color3* color, size_t size);
	void EmitParticles();

	long GetParticleCount();
	bool GetActiveParticle();
	bool GetIsDestroyed();

private:
	Particle(Vector3f pos, Vector3f oppositePos, Vector3f vel,
		Vector3f randomVel, Color3 col, Vector3f norm, int minLife, int maxLife);

	void UpdateParticles(float dt);

	bool autoDestruct;
	bool isDestroyed;
	Time* particleTime;
	float destructTime;

	int minEnergy;
	int maxEnergy;
	float life;
	bool isActive;
	int particleCount;

	long curParticleCount;

	Vector3f particlePos;
	Vector3f randomVelocity;
	Vector3f ellipsoid;
	Vector3f normal;

	Color3* colors;
	unsigned int colorSize;

	Particle* start;
	Particle* end;
	Particle* last;
protected:
	bool IsInsideSphere(Vector3f center, double radius, Vector3f pos);
};

ATOM_END

#endif // _ATOM_PARTICLE_H_