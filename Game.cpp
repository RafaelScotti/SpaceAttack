#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Game.h"

void Game::addPipe(Enemy e){
	Game::pipes.push_back(e);
}

Player Game::getPlayer()
{
	return Game::player;
}

void Game::creteGame()
{
	Game::speed = 5;

	Game::p1.setZPosEnemy(-600);
	Game::p2.setZPosEnemy(-900);
	Game::p3.setZPosEnemy(-1200);

	Game::addPipe(Game::p1);
	Game::addPipe(Game::p2);
	Game::addPipe(Game::p3);

	//scene.setTitle("The Begin");
	scene.draw();

	glPushMatrix();
		Game::pipes[0].draw();
		Game::pipes[1].draw();
		Game::pipes[2].draw();
	glPopMatrix();

	player.draw();

	//animacoes
	glPushMatrix();
	Game::pipes[0].moveEnemy(0,0,0,Game::speed);
	Game::pipes[1].moveEnemy(0,0,0,Game::speed);
	Game::pipes[2].moveEnemy(0,0,0,Game::speed);
	player.animate();
	scene.animate();



	glPopMatrix();


}

void Game::start()
{
	Game::startGame = true;

}

void Game::pause()
{
	Game::reset();
	Game::startGame = false;
}

void Game::save()
{
}

void Game::exit()
{
	//exit(0);
	Game::startGame = false;
}

void Game::reset()
{
	player.reset();
	pipes.clear();
	Game::startGame = false;

}

bool Game::hasStarted()
{
	return Game::startGame;
}


void Game::controller(int key)
{
	if (key == GLUT_KEY_RIGHT) {
		if (player.getX() < 40) {
			player.setX(8.0);
		}
	}
	if (key == GLUT_KEY_LEFT) {
		if (player.getX() > -40) {
			player.setX(-8.0);
		}
	}
	if(key == GLUT_KEY_UP){
		if(!hasStarted()){
			reset();
			start();
		}

	}


}

void Game::collision(){
	if(Game::pipes[0].getZPosEnemy() == player.getZ()){
		//Game::pause();
		if((Game::pipes[0].getXP1() <=  player.getX() && Game::pipes[0].getXP2() >= player.getX())){
			//Game::pause();
			//Game::incScore();
		}
	}else{
		if(Game::pipes[1].getZPosEnemy() == player.getZ()){
		//Game::pause();
			if((Game::pipes[1].getXP1() <= player.getX() && Game::pipes[1].getXP2() >= player.getX())){
				//Game::pause();
				//Game::incScore();
			}
		}else{
			if(Game::pipes[2].getZPosEnemy() == player.getZ()){
	 			//Game::pause();
				if((Game::pipes[2].getXP1() <= player.getX() && Game::pipes[2].getXP2() >= player.getX())){
					//Game::pause();
					//Game::incScore();
				}
			}
		}
	}
}



void Game::incScore(){
	Game::score++;
}

int Game::getScore(){
	return Game::score;
}

void Game::setRecord(int newScore){
	if(Game::score > Game::record){
		Game::record = Game::score;
	}
}

int Game::getRecord(){
	return Game::record;
}


void Game::drawText(const char * text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[32];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	//gluOrtho2D(-350, 350, -450, 450);
	glOrtho(0, 800, 0, 600, -1, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i<length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);

	delete matrix;
}


void Game::showMenu(){
	std::string text;
	text = "Score: "; //+ to_string(game.getScore());
	glColor3f(1.0, 0.0, 0.0);
	drawText(text.data(), text.size(), 330, 500);

	text = "Record: ";// + to_string(game.getRecord());
	glColor3f(0.0, 0.0, 0.0);
	drawText(text.data(), text.size(), 320, 470);

	text = "\"SPACE ATTACK\"";
	glColor3f(0.5, 0.0, 0.0);
	drawText(text.data(), text.size(), 350, 550);

	glPushMatrix();
		glTranslatef(-25, 30, -200);
		glRotatef(200, 0, 1, 0);
		glRotatef(135, 1, 0, 0);
		glColor4f(1.1f, 1.0f, 1.0f, 1.0);

		player.draw();
		player.animate();
	glPopMatrix();


	text = "Press UP arrow to play";
	glColor3f(0.2, 0.8, 0.2);
	drawText(text.data(), text.size(), 500, 50);
}
