#include "masspoint.hpp"

MassPoint::MassPoint(olc::PixelGameEngine* pge, olc::vf2d pos, float velocity, float force, float mass) {
	this->pge = pge;
	this->pos = pos;
	this->velocity = velocity;
	this->force = force;
	this->mass = mass;
};

void MassPoint::draw() {
	pge->DrawRect(pos.x, pos.y, 50, 80, { 255, 255, 255});
	pge->FillRect(pos.x, pos.y, 50, 80, { 255, 255, 255 });
}
