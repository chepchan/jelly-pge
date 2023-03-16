#include "masspoint.hpp"

Particle::Particle(olc::PixelGameEngine* pge, olc::vf2d pos, olc::vf2d velocity, olc::vf2d force, float mass) {
	this->pge = pge;
	this->pos = pos;
	this->velocity = velocity;
	this->force = force;
	this->mass = mass;
}

void Particle::connect(olc::vf2d pos_1, olc::vf2d pos_2, float dt) {

	olc::Pixel lineColor = { 143, 203, 217 };
	pge->DrawLineDecal(pos_1, pos_2, lineColor);
}

olc::vf2d Particle::circle() {
	const float tau = 6.28f;
	const int n = 8;
	const float step = tau / (float)n;
	const float radius = 6.0f;
	float x = 0.0f;
	float y = 0.0f;
	olc::vf2d place = { x, y };

	for (int i = 0; i < n; i++) {
		float angle = step * (float)i;

		x = radius * cos(angle);
		y = radius * sin(angle);
	}
	return place;
}

void Particle::update(float dt) {
	//velocity.x += (force.x / mass) * dt;
	velocity.y += (force.y / mass) * dt;
	//pos.x += velocity.x * dt;
	pos.y += velocity.y * dt;

	pge->DrawCircle((int)pos.x, (int)pos.y, 10, { 143, 203, 217 });
	pge->FillCircle((int)pos.x, (int)pos.y, 10, { 143, 203, 217 });

}