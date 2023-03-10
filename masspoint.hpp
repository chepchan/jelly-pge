#include "olcPixelGameEngine.h"

struct Pointf {
	float x;
	float y;
};

class MassPoint {
public:
	olc::PixelGameEngine* pge;

	Pointf pos;
	float velocity;
	float force;
	float mass;
	MassPoint(olc::PixelGameEngine* pge, Pointf pos, float velocity, float force, float mass);

};