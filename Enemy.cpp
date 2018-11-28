#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Enemy.h"
Enemy::Enemy(){
	//Enemy::
	Enemy::setTxyz(0 ,-20, 20);
	Enemy::auxRotX = 0;
	Enemy::setXP1(Enemy::getPipeSize() - 80);
	Enemy::setXP2(getXP1() + 30);

}

void Enemy::setTxyz(int x, int y, int z){
	Enemy::tx += x;
	Enemy::ty += y;
	Enemy::tz += z;
}
int Enemy::getTxyz(char xyz){
	if(xyz == 'x'){
		return Enemy::tx;
	}else if(xyz == 'y'){
		return Enemy::ty;
	}else if(xyz == 'z'){
		return Enemy::tz;
	}else{

	}
}

void Enemy::setRxyz(int x, int y, int z){
	Enemy::rx = x;
	Enemy::ry = y;
	Enemy::rz = z;
}
int Enemy::getRxyz(char xyz){
	if(xyz == 'x'){
		return Enemy::rx;
	}else if(xyz == 'y'){
		return Enemy::ry;
	}else if(xyz == 'z'){
		return Enemy::rz;
	}else{

	}
}

void Enemy::setKind(int kind)
{
	Enemy::kind = kind;
}

int Enemy::getKind()
{
	return Enemy::kind;
}

void Enemy::setLife(int life)
{
	Enemy::life = life;
}

int Enemy::getLife()
{
	return Enemy::life;
}


void Enemy::setZPosEnemy(int tz){
	Enemy::zPosEnemy = tz;
}

int Enemy::getZPosEnemy(){
	return Enemy::zPosEnemy;
}

void Enemy::setPipeSize(int x){
	Enemy::pipeSize = x;
}

int Enemy::getPipeSize(){
	return Enemy::pipeSize;
}

int Enemy::getXP1(){
	return Enemy::xP1;
}
int Enemy::getXP2() {
	return Enemy::xP2;
}

void Enemy::setXP1(int x1){

	Enemy::xP1 = x1;
}
void Enemy::setXP2(int x2){
	Enemy::xP2 = x2;
}


void Enemy::draw()
{


	glPushMatrix();
	glTranslatef(-80, -30, Enemy::getZPosEnemy());
	glRotatef(Enemy::auxRotX, 1, 0, 0);
	setRotation(90, 0, 1, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glutWireCone(20, Enemy::getPipeSize() , 20, 0); //Enemy::sizeRand max 130
	glPopMatrix();


	glPushMatrix();
	glTranslatef(80, -30, Enemy::getZPosEnemy());
	glRotatef(Enemy::auxRotX, 1, 0, 0);
	setRotation(270, 0, 1, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glutWireCone(20, 100-Enemy::getPipeSize() , 20, 0); //Enemy::sizeRand max 130
	glPopMatrix();



}



void Enemy::moveEnemy(int x, int y, int z, int speed) {

	//glRotatef(auxRotX, 1, 1, 0);
	Enemy::setXP1(Enemy::getPipeSize() - 80);
	Enemy::setXP2(getXP1() + 30);

	if(Enemy::getZPosEnemy() < 300){
		Enemy::zPosEnemy += speed;
		//Enemy::setTxyz(0, 0, speed);
		//glTranslatef(Enemy::getTxyz('x'), Enemy::getTxyz('y'), Enemy::getZPosEnemy());
		Enemy::auxRotX += 1;
	}
	if(Enemy::getZPosEnemy() >= 300) {
		int aux = 0;
		if(Enemy::tx > 30){
			aux = Object::random(1, 2);
		}else if(Enemy::tx < -30) {
			aux = Object::random(2, 3);
		}else {
			aux = Object::random(1, 3);
		}

		Enemy::setZPosEnemy(-600);


		Enemy::pipeSize = Object::random(0, 100);


	}

	//auxRotX += 0.5;
}
