#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Object.h"


class Enemy : public Object
{

private:

	int kind;
	int life;

	int tx, ty, tz;
	int rx, ry, rz;

	float auxRotX;
	int sizeRand;

	int zPosEnemy;
	int pipeSize;

	int xP1;
	int xP2;


public:

	Enemy();

	int getXP1();
	int getXP2();
	void setXP1(int x1);
	void setXP2(int x2);

	void setZPosEnemy(int tz);
	int getZPosEnemy();

	void setPipeSize(int x);
	int getPipeSize();

	void setTxyz(int x, int y, int z);
	int getTxyz(char xyz);

	void setRxyz(int x, int y, int z);
	int getRxyz(char xyz);

	void setKind(int kind);
	int getKind();

	void setLife(int life);
	int getLife();

	//int definePosition(int r);
	void draw();

	void moveEnemy(int x, int y, int z, int speed);


};

#endif
