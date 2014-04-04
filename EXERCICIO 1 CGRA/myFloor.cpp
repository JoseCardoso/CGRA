#include "myFloor.h"


void myFloor::draw()
{
	glPushMatrix();
	myUnitCube floor;
	glScaled(8,0.1,6);
	floor.draw();
	glPopMatrix();
}