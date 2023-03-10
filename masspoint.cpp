#include "masspoint.hpp"

MassPoint::MassPoint(olc::PixelGameEngine* pge, Pointf pos, float velocity, float force, float mass) {
	this->pge = pge;
	this->pos = pos;
	this->velocity = velocity;
	this->force = force;
	this->mass = mass;
};
