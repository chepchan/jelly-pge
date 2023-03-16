#define OLC_PGE_APPLICATION
#include <iostream>

#include "olcPixelGameEngine.h"
#include "masspoint.hpp"
//#include "spring.hpp"


class JELLY : public olc::PixelGameEngine
{
public:

	JELLY() {
		sAppName = "Jelly";
	}
	~JELLY() {
		delete pointPos;
		delete Shape;
	}

	float pointMass = 1.0f;
	olc::vf2d pointVelocity = { 0.0f, 170.0f };
	olc::vf2d pointForce = { 0.0f, 9.8f };

	Particle** Shape = nullptr;
	olc::vf2d** pointPos = nullptr; 

	bool OnUserCreate() override
	{
		const int n = 9;

		Shape = new Particle * [n];
		pointPos = new olc::vf2d * [n];

		const float tau = 6.28f;
		const float step = tau / (float)n;
		const float radius = 100.0f;
		olc::vf2d center = { 190.0f, 190.0f };
		for (int i = 0; i < n; i++) {
			float angle = step * (float)i;
			float x = center.x + radius * cos(angle);
			float y = center.y + radius * sin(angle);
			pointPos[i] = new olc::vf2d(x, y);
		}

		for (int i = 0; i < 5; i++) {
			Shape[i] = new Particle(this, *pointPos[i], pointVelocity, pointForce, pointMass);
		}

		return true;
	}

	bool OnUserUpdate(float deltaTime) override
	{
		Clear(olc::Pixel(0, 0, 0));

		for (int i = 0; i < 5; i++) {
			Shape[i]->update(deltaTime);
		}

		return true;
	}
};


int main()
{

	JELLY game;
	const int width = 1400;
	const int height = 950;
	const int pixelScale = 1;

	if (!game.Construct(width, height, pixelScale, pixelScale)) return EXIT_FAILURE;

	game.Start();

	return EXIT_SUCCESS;
}