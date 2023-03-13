#pragma once
#include "olcPixelGameEngine.h"

class Spring {
public:
	int id;
	olc::PixelGameEngine* pge;

	float damp;
	float mass = 1;
	float sprC;
	olc::vf2d pos;
	olc::vf2d restPos = { pos.x, pos.y };
	olc::vf2d velocity = { 0.0, 0.0 };
	olc::vf2d force = { 0.0, 0.0 };
	float acceleration = 0.0;

	bool move = false;
	olc::vf2d dis;

	Spring(olc::PixelGameEngine* pge, olc::vf2d pos, float damp, float mass, float sprC, int id);

	void update();
	void moveSpring();
	bool overEvent();
	//void neZnam();
	//bool otherOver();
	int distance(olc::vf2d a, olc::vf2d b);
	void display();
	void pressed();
	void released();

	void FINALupdate();
};