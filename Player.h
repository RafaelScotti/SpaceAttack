#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Object.h"

class Player :
	public Object
{


	float x;
	float y;
	float z;


public:

	Player();
	int auxRotate;
	float getX();
	float getZ();

	void setX(float x);


	void draw();
	void animate();
	void reset();
};
#endif
