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
	//~JELLY() {
	//	//delete point;
	//	delete Shapes;
	//}

	olc::vf2d pointPos_0 = { 320.0f, 20.0f };
	olc::vf2d pointPos_1 = { 370.0f, 70.0f };
	olc::vf2d pointPos_2 = { 420.0f, 120.0f };
	olc::vf2d pointPos_3 = { 470.0f, 170.0f };
	olc::vf2d pointPos_4 = { 520.0f, 220.0f };

	float pointMass = 1.0f;
	olc::vf2d pointVelocity = { 0.0f, 170.0f };
	olc::vf2d pointForce = { 0.0f, 9.8f };

	//Particle* point = nullptr;
	Particle* Shape[5];

	bool OnUserCreate() override
	{
		Shape[0] = new Particle(this, pointPos_0, pointVelocity, pointForce, pointMass);
		Shape[1] = new Particle(this, pointPos_1, pointVelocity, pointForce, pointMass);
		Shape[2] = new Particle(this, pointPos_2, pointVelocity, pointForce, pointMass);
		Shape[3] = new Particle(this, pointPos_3, pointVelocity, pointForce, pointMass);
		Shape[4] = new Particle(this, pointPos_4, pointVelocity, pointForce, pointMass);

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