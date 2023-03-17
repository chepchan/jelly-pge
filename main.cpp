#define OLC_PGE_APPLICATION
#include <iostream>

#include "olcPixelGameEngine.h"
#include "masspoint.hpp"
//#include "spring.hpp"

class JELLY : public olc::PixelGameEngine
{
public:
	const int numberOfParticles = 12;

	JELLY() {
		sAppName = "Jelly";
	}
	~JELLY() {
		delete particlePos;
		delete particles;
	}

	void connect(olc::vf2d* pos_1, olc::vf2d* pos_2) {

		olc::Pixel lineColor = { 225, 176, 255 };
		DrawLineDecal(*pos_1, *pos_2, lineColor);
	}

	float particleMass = 1.0f;
	olc::vf2d particleVelocity = { 0.0f, 170.0f };
	olc::vf2d particleForce = { 0.0f, 9.8f };

	Particle** particles = nullptr;
	olc::vf2d** particlePos = nullptr; 

	bool OnUserCreate() override
	{
		particles = new Particle * [numberOfParticles];
		particlePos = new olc::vf2d * [numberOfParticles];

		const float tau = 6.28f;
		const float step = tau / (float)numberOfParticles;
		const float radius = 100.0f;
		olc::vf2d center = { 190.0f, 190.0f };
		for (int i = 0; i < numberOfParticles; i++) {
			float angle = step * (float)i;
			float x = center.x + radius * cos(angle);
			float y = center.y + radius * sin(angle);
			particlePos[i] = new olc::vf2d(x, y);
		}

		for (int i = 0; i < numberOfParticles; i++) {
			particles[i] = new Particle(this, *particlePos[i], particleVelocity, particleForce, particleMass);
		}

		return true;
	}

	bool OnUserUpdate(float deltaTime) override
	{
		Clear(olc::Pixel(26, 22, 28));

		for (int i = 0; i < numberOfParticles - 1; i++) {
			particles[i]->draw(3);
			connect(&particles[i]->pos, &particles[i + 1]->pos);
			if (particles[i]->collide()) {
				particles[i]->update(deltaTime);
			}
		}
		particles[numberOfParticles - 1]->draw(3);
		connect(&particles[numberOfParticles - 1]->pos, &particles[0]->pos);
		if (particles[numberOfParticles - 1]->collide()) {
			particles[numberOfParticles - 1]->update(deltaTime);
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