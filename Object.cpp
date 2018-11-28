#include "Object.h"

void Object::setName(std::string name)
{
	Object::name = name;
}

std::string Object::getName()
{
	return Object::name;
}

void Object::setVisible(bool v)
{
	setVisible(v);
}

bool Object::isVisible()
{
	return Object::visible;
}

void Object::setTranslation(float x, float y, float z)
{
	Object::translation[0] = x;
	Object::translation[1] = y;
	Object::translation[2] = z;

	glTranslatef(x, y, z);

}

void Object::setScale(float x, float y, float z)
{
	Object::scale[0] = x;
	Object::scale[1] = y;
	Object::scale[2] = z;
	glScalef(x, y, z);
}

void Object::setRotation(float angle, float x, float y, float z)
{
	Object::rotation[0] = angle;
	Object::rotation[1] = x;
	Object::rotation[2] = y;
	Object::rotation[3] = z;
	glRotatef(angle, x, y, z);
}

float Object::getTranslation(int pos)
{
	return Object::translation[pos];
}

float Object::getScale(int pos)
{
	return Object::scale[pos];
}

float Object::getRotation(int pos)
{
	return Object::rotation[pos];
}

int Object::random(int min, int max) {
	int output = min + (rand() % static_cast<int>(max - min + 1));

	return output;
}



Object::Object()
{
}


Object::~Object()
{
}
