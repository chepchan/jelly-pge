#include "masspoint.hpp"

Particle::Particle(olc::PixelGameEngine* pge, olc::vf2d pos, olc::vf2d velocity, olc::vf2d force, float mass) {
	this->pge = pge;
	this->pos = pos;
	this->velocity = velocity;
	this->force = force;
	this->mass = mass;
}

void Particle::update(float dt) {
	//velocity.x += (force.x / mass) * dt;
	velocity.y += (force.y / mass) * dt;
	//pos.x += velocity.x * dt;
	pos.y += velocity.y * dt;

	pge->DrawCircle(pos.x, pos.y, 10, { 143, 203, 217 });
	pge->FillCircle(pos.x, pos.y, 10, { 143, 203, 217 });
}