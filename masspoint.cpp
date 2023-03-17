#include "masspoint.hpp"

Particle::Particle(olc::PixelGameEngine* pge, olc::vf2d pos, olc::vf2d velocity, olc::vf2d force, float mass) {
	this->pge = pge;
	this->pos = pos;
	this->velocity = velocity;
	this->force = force;
	this->mass = mass;
}

void Particle::draw(int radius) {
	pge->DrawCircle((int)pos.x, (int)pos.y, radius, { 225, 176, 255 });
	pge->FillCircle((int)pos.x, (int)pos.y, radius, { 225, 176, 255 });
}

void Particle::update(float dt) {
	velocity.x += (force.x / mass) * dt;
	velocity.y += (force.y / mass) * dt;
	pos.x += velocity.x * dt;
	pos.y += velocity.y * dt;
}

bool Particle::collide() {
	if (pos.x < pge->ScreenWidth() - 10 
		&& pos.y < pge->ScreenHeight() - 10
		&& pos.x > 10
		&& pos.y > 10) { return true; }
	else { return false; }
}