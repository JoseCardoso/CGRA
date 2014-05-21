#pragma once
#include "myunitcube.h"
class myChair : public myUnitCube
{
	float angle, tx, tz;
public:
	myChair(float anglo,float x,float z);
	void draw();
};

