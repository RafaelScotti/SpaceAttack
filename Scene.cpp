#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Scene.h"


std::string Scene::getTitle()
{
	return 0;
}

void Scene::setTitle(std::string title)
{
}

void Scene::draw()
{

	glEnable(GL_BLEND);


	// left pipe
	glPushMatrix();
	glTranslatef(0, -30, 0);
	glRotatef(270, 1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glColor4f(1.0, 0.0, 0.0, Scene::random(0, Scene::random(0,9)));
	glVertex2f(-80, 900);

	glColor4f(0.0, 1.0, 0.0, 0.0);
	glVertex2f(80, 900);

	glColor4f(0.0, 0.0, 1.0, 0.0);
	glVertex2f(80, -100);

	glColor4f(1.0, 0.0, 1.0, 1.0);
	glVertex2f(-80, -100);
	glEnd();
	glPopMatrix();



	//right pipe
	glPushMatrix();
	glTranslatef(0, -29, 0);
	glRotatef(270, 1.0, 0.0, 0.0);
	glLineWidth(50);
	glBegin(GL_LINE_STRIP);
	glColor4f(1.0, 0.0, 0.0, 0.0);
	glVertex2f(-80, 900);
	glColor4f(0.0, 1.0, 0.0, 0.0);
	glVertex2f(80, 900);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(80, -100);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-80, -100);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-80, 900);
	glEnd();
	glPopMatrix();

	//black hole
	glPushMatrix();
		glTranslatef(0, 30, -770);
		glRotatef(180, 1, 0, 0);
		glRotatef(Scene::auxRotate, 0, 0, 1);


		glColor4f(1.0, 0.0, Scene::random(0,1), Scene::random(0, Scene::random(0,9)) );
		glutWireTorus(70, 200, 20, 7);
	glPopMatrix();




	// stars
	glPushMatrix();
		glTranslatef(-120, 30, Scene::auxTranslate);
		glRotatef(Scene::auxRotate, 0, 0, 1);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0);
		glutSolidSphere(40, 10, 6);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(120, 35, Scene::auxTranslate-300);
		glRotatef(Scene::auxRotate, 0, 1, 1);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0);
		glutSolidSphere(40, 10, 6);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-100, 50, Scene::auxTranslate+400);
		glRotatef(Scene::auxRotate, 1, 1, 1);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0);
		glutSolidSphere(40, 10, 6);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-150, 30, Scene::auxTranslate-1200);
		glRotatef(Scene::auxRotate, 1, 0, 1);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0);
		glutSolidSphere(40, 10, 6);
	glPopMatrix();



}


void Scene::animate() {
	Scene::auxRotate+=1;
	//int cont = 0;
	Scene::auxTranslate += 1;
	if(Scene::auxTranslate > 100){
		Scene::auxTranslate = -600;
	}
}



int Scene::random(int min, int max) {
	int output = min + (rand() % static_cast<int>(max - min + 1));

	return output;
}
