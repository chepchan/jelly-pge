#include <math.h>

#include "spring.hpp"
#include "olcPixelGameEngine.h"

Spring::Spring(olc::PixelGameEngine* pge, olc::vf2d pos, float damp, float mass, float sprC, int id) {
	this->pge = pge;
	this->pos = pos;
	this->damp = damp;
	this->mass = mass;
	this->sprC = sprC;
	this->id = id;
}

void Spring::update() {
	force.y = -sprC * (pos.y - restPos.y);
	force.x = -sprC * (pos.x - restPos.x);

	acceleration = force.x / mass;

	velocity.y = damp * (velocity.y + acceleration);
	velocity.x = damp * (velocity.x + acceleration);

	pos.y = pos.y + velocity.y;
	pos.x = pos.x + velocity.x;
}

void Spring::moveSpring() {
	restPos.y = (float)pge->GetMouseY();
	restPos.x = (float)pge->GetMouseX();
}

int Spring::distance(olc::vf2d a, olc::vf2d b) {
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

bool Spring::overEvent() {
	dis.x = pos.x - (float)pge->GetMouseX();
	dis.y = pos.y - (float)pge->GetMouseY();
	int dist = distance(dis, pos);
	return (dist < 10) ? true : false;
}

void Spring::display() {
	if (overEvent()) {
		pge->DrawCircle((int)pos.x, (int)pos.y, 10, { 200, 0, 0 });
		pge->FillCircle((int)pos.x, (int)pos.y, 10, { 200, 0, 0 });
	}
	else {
		pge->DrawCircle((int)pos.x, (int)pos.y, 10, { 255, 0, 0 });
		pge->FillCircle((int)pos.x, (int)pos.y, 10, { 255, 0, 0 });
	}
}

void Spring::pressed() {
	if (overEvent()) {
		move = true;
	}
	else { move = false; }
}

void Spring::released() {
	move = false;
	restPos.x = pos.y;
	restPos.y = pos.y;
}

void Spring::FINALupdate() {
	update();
	display();
	pressed();
	released();
	moveSpring();
}