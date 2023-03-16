#define OLC_PGE_APPLICATION
#include <iostream>

#include "olcPixelGameEngine.h"
#include "masspoint.hpp"
//#include "spring.hpp"

class JELLY : public olc::PixelGameEngine
{
public:
	const int numberOfPoints = 9;

	JELLY() {
		sAppName = "Jelly";
	}
	~JELLY() {
		delete pointPos;
		delete particles;
	}

	void connect(olc::vf2d* pos_1, olc::vf2d* pos_2) {

		olc::Pixel lineColor = { 143, 203, 217 };
		DrawLineDecal(*pos_1, *pos_2, lineColor);
	}

	float pointMass = 1.0f;
	olc::vf2d pointVelocity = { 0.0f, 170.0f };
	olc::vf2d pointForce = { 0.0f, 9.8f };

	Particle** particles = nullptr;
	olc::vf2d** pointPos = nullptr; 

	bool OnUserCreate() override
	{
		particles = new Particle * [numberOfPoints];
		pointPos = new olc::vf2d * [numberOfPoints];

		const float tau = 6.28f;
		const float step = tau / (float)numberOfPoints;
		const float radius = 100.0f;
		olc::vf2d center = { 190.0f, 190.0f };
		for (int i = 0; i < numberOfPoints; i++) {
			float angle = step * (float)i;
			float x = center.x + radius * cos(angle);
			float y = center.y + radius * sin(angle);
			pointPos[i] = new olc::vf2d(x, y);
		}

		for (int i = 0; i < numberOfPoints; i++) {
			particles[i] = new Particle(this, *pointPos[i], pointVelocity, pointForce, pointMass);
		}

		return true;
	}

	bool OnUserUpdate(float deltaTime) override
	{
		Clear(olc::Pixel(0, 0, 0));

		for (int i = 0; i < numberOfPoints - 1; i++) {
			particles[i]->update(deltaTime);
			connect(&particles[i]->pos, &particles[i + 1]->pos);
		}
		particles[numberOfPoints - 1]->update(deltaTime);
		connect(&particles[numberOfPoints - 1]->pos, &particles[0]->pos);

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