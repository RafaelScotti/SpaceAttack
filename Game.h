#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


#include "Scene.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

class Game
{
private:

	bool startGame;
	int score;
	int record;

	Scene scene;
	Player player;
	Enemy enemy;
	Enemy p1;
	Enemy p2;
	Enemy p3;

	int speed;


public:
	std::vector<Enemy> pipes;
	void addPipe(Enemy e);
	//Enemy getEnemy()

	Player getPlayer();

	void creteGame();

	void start();

	void pause();

	void save();

	void exit();

	void reset();

	bool hasStarted();

	void controller(int key);

	void collision();

	void incScore();

	int getScore();

	void setRecord(int newScore);

	int getRecord();

	void drawText(const char * text, int length, int x, int y);

	void showMenu();

};
#endif
