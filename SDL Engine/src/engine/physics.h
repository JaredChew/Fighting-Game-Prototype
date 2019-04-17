#pragma once

#include <iostream>
#include <math.h>
#include <SDL.h>

class Physics {

public:
	Physics();
	~Physics();

	//Axis aligned bounding box [AABB]
	bool collisionBox(SDL_Rect colidded, SDL_Rect colidder);

	int collisionCircle(int mainPosX, int mainPosY, int clashPosX, int clashPosY);

};