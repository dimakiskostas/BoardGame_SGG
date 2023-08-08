#pragma once

#include <random>
#include <stdlib.h>

#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 18.0f


#define ASSET_PATH ".\\assets\\"

#define PLAYER_SIZE 1.0f

//motion ranges for all players!
#define PLAYER_MOTION_RANGE_SHARK 5.0f
#define PLAYER_MOTION_RANGE_SQUID 1.0f
#define PLAYER_MOTION_RANGE_XIFIAS 4.0f
#define PLAYER_MOTION_RANGE_FALAINA 6.0f
#define PLAYER_MOTION_RANGE_XTAPODI 2.5f


//atack motion ranges!
#define PLAYER_ATTACK_RANGE_SHARK 3.4f
#define PLAYER_ATTACK_RANGE_FALAINA 4.4f
#define PLAYER_ATTACK_RANGE_XIFIAS 3.0f
#define PLAYER_ATTACK_RANGE_SQUID 1.4f
#define PLAYER_ATTACK_RANGE_XTAPODI 1.8f

#define SETCOLOR(c, r, g, b) {c[0] = r; c[1] = g; c[2] = b;}



#define RAND0TO1() (rand()/(float)RAND_MAX)




inline float distance(float x1, float y1, float x2, float y2) {
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}