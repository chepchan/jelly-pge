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

	Pointf pointPos = { 200.0, 200.0 };

	MassPoint* point = nullptr;

	bool OnUserCreate() override
	{
		point = new MassPoint(this, pointPos, 1.0, 1.0, 3.0);

		return true;
	}

	bool OnUserUpdate(float deltaTime) override
	{
		Clear(olc::Pixel(80, 100, 180));

		//MassPoint& point = point;

		double gravity = -9.8 * (double)point->mass;
		point->force = gravity; //( * spring force)
		point->velocity = (point->force / point->mass) * deltaTime;

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