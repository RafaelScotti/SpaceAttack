#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Player.h"

Player::Player()
{
	Player::x = 0;
	Player::y = -20;
	Player::z = 80;

}

float Player::getX()
{
	return Player::x;
}

void Player::setX(float x)
{
	Player::x += x;
}

float Player::getZ(){
	return Player::z;
}

void Player::reset(){
	Player::x = 0;
	Player::y = -20;
	Player::z = 80;
}

void Player::draw()
{
	glPushMatrix();

	setTranslation(Player::x, Player::y, Player::z);

	setRotation(90, 1, 0, 0);
	setRotation(Player::auxRotate, 0.0, 0.0, 1.0);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glColor4f(1.1f, 1.0f, 1.0f, 1.0);
		glutWireTorus(5, 10, 20, 7);
	glPopMatrix();


}

void Player::animate(){

	Player::auxRotate+=3;
}
