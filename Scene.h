#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Object.h"


class Scene
{
private:
	std::string title;

	int auxRotate;
	int auxTranslate;




public:
	std::string getTitle();

	void setTitle(std::string title);

	void draw();

	void animate();

	int random(int min, int max);
};
#endif
