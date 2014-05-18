#include "myLamp.h"

myLamp::myLamp(int slices, int stacks, bool smooth) {
	this->slices=slices;
	this->stacks=stacks;
	this->smooth=smooth;
}


void myLamp::draw()
{

	double myPi = acos(-1.0);
	double a = 0;
	double toG = myPi/180;
	double da = 360/ (double) slices;

	double x1 = 1.0 , y1=0.0; 
	a+=da;
	double x2 = cos(a*toG);
	double y2 = sin(a*toG);



	for(int j = 0 ; j < stacks ; j++)
	{

		for (int i = 0 ; i < slices/2 ; i++)
		{

			glBegin(GL_TRIANGLES);
			glNormal3d(0,0,-1);
			glVertex3d(x2,y2,0);
			glVertex3d(x1 ,y1 ,0);
			glVertex3d(0,0,0);

			glEnd();


			x1 = x2;
			y1 = y2;

			a += da;

			x2 = cos(a*toG);
			y2 = sin(a*toG);

		}


	}

}