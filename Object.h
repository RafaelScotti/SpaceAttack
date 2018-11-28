#pragma once
#include <iostream>
#include "GL/freeglut.h"
#include <cstdlib>
class Object
{

private:
	std::string name;

	bool visible;

	float translation[3];

	float scale[3];

	float rotation[4];

public:
	Object();
	~Object();


	void setName(std::string name);

	std::string getName();

	void setVisible(bool v);

	bool isVisible();

	virtual void draw() = 0;

	void setTranslation(float x, float y, float z);

	void setScale(float x, float y, float z);

	void setRotation(float angle, float x, float y, float z);

	float getTranslation(int pos);

	float getScale(int pos);

	float getRotation(int pos);

	int random(int min, int max);

};
