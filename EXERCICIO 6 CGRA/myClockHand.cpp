#include "myClockHand.h"


myClockHand:: myClockHand(){
	angle = 0.0;
}

void myClockHand :: draw()
{
	glPushMatrix();
		
		glRotated(angle , 0,0,1);
		glBegin(GL_TRIANGLES); 
		glNormal3d(0,0,1);
		glVertex3d(0.01,0,0);
		glVertex3d(0,0.8,0);
		glVertex3d(-0.01,0,0);
		glEnd();

	glPopMatrix();
}

void myClockHand :: setAngle( float angle)
{
	this->angle = angle;
}

float myClockHand:: getAngle() const
{
	return angle;
}