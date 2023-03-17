#pragma once
#include "olcPixelGameEngine.h"

class Particle {
public:
	olc::PixelGameEngine* pge;

	olc::vf2d pos;
	olc::vf2d velocity;
	olc::vf2d force;
	float mass;

	Particle(olc::PixelGameEngine* pge, olc::vf2d pos, olc::vf2d velocity, olc::vf2d force, float mass);

	void draw(int radius);
	void update(float dt);
	bool collide();
};