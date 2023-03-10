#include "olcPixelGameEngine.h"

struct Pointf {
	float x;
	float y;
};

class MassPoint {
public:
	olc::PixelGameEngine* pge;

	olc::vf2d pos;
	float velocity;
	float force;
	float mass;
	MassPoint(olc::PixelGameEngine* pge, olc::vf2d pos, float velocity, float force, float mass);

	void draw();
};