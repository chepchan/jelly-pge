#define OLC_PGE_APPLICATION
#include <iostream>

#include "olcPixelGameEngine.h"
#include "masspoint.hpp"

class JELLY : public olc::PixelGameEngine
{
public:

	JELLY() {
		sAppName = "Jelly";
	}
	~JELLY() {
		delete point;
	}

	olc::vf2d pointPos = { 160.0f, 10.0f };
	olc::vf2d pointVelocity = { 0.0f, 0.0f };
	olc::vf2d pointForce = { 0.0f, 9.8f };
	float pointMass = 1.0f;

	Particle* point = nullptr;

	bool OnUserCreate() override
	{
		point = new Particle(this, pointPos, pointVelocity, pointForce, pointMass);

		return true;
	}

	bool OnUserUpdate(float deltaTime) override
	{
		Clear(olc::Pixel(0, 0, 0));

		point->update(deltaTime);
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