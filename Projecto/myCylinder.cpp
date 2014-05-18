#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices=slices;
	this->stacks=stacks;
	this->smooth=smooth;
}


void myCylinder::draw()
{   /*
	int temp = slices/4;
	int k = 0;
	int counter = 0;
	*/
	double myPi = acos(-1.0);
	double a=0;
	double da =360/ (double) slices;

	double x1 = 1.0 , y1=0.0; 
	a+=da;
	double x2=cos(a*myPi/180);
	double y2=sin(a*myPi/180);
	double tx = 0;
	double ty = 0;


	for (int i = 0 ; i < slices ; i++)
	{

		glBegin(GL_TRIANGLES);
		glNormal3d(0,0,-1);
		glVertex3d(x2,y2,0);
		glVertex3d(x1 ,y1 ,0);
		glVertex3d(0,0,0);

		glEnd();


		glBegin(GL_TRIANGLES);
		glNormal3d(0,0,1);
		/*  NOT WORKING Properly
		glTexCoord2d(tx , ty); */glVertex3d(x1 ,y1 , 1);
		/*
		if (k == 0){

			if( counter < temp){
				tx += (double) 1/temp;
				counter++;
			}
			else{
				ty += (double) 1/temp;
				counter = 0;
				k++;
			}
		}
		else if (k == 1){

			if( counter < temp){
				ty += (double) 1/temp;
				counter++;
			}
			else{
				tx -= (double) 1/temp;
				counter = 0;
				k++;
			}
		}
		else if (k == 2){

			if( counter < temp){
				tx -= (double) 1/temp;
				counter++;
			}
			else{
				ty -= (double) 1/temp;
				counter = 0;
				k++;
			}
		}
		else if (k == 3){

			if( counter < temp){
				ty -= (double) 1/temp;
				counter++;
			}
		
		}

		*/
		/*glTexCoord2d(tx,ty); */glVertex3d(x2 ,y2 ,1);
		/*glTexCoord2d(0.5,0.5);*/ glVertex3d(0,0,1);
		glEnd();


		double inc = 1.0 / stacks;

		
		for ( int j=0 ; j < stacks ;j++)
		{

			glBegin(GL_QUADS);
			if (!smooth)  // isto sao as normais usadas para  flat shadding
			{
			double xN = (x1+x2)/sqrt(pow((x1+x2),2) + pow((y1+y2),2));
			double yN = (y1+y2)/sqrt(pow((x1+x2),2) + pow((y1+y2),2));
			glNormal3d(xN,yN,0);
			glVertex3d(x1 ,y1 , j*inc);
			glVertex3d(x2,y2,j*inc);
			glVertex3d(x2,y2,(j+1)*inc);
			glVertex3d(x1 ,y1 , (j+1)*inc);
			}
			else
			{
				double kX1 =sqrt( x1*x1 + y1*y1);
				double kX2 =sqrt( x2*x2 + y2*y2);
				double xN1 = x1/kX1;   // normais para smooth shading como num cilindro
				double yN1 = y1/kX1;    
				double xN2 = x2/kX2;
				double yN2 = y2/kX2;
				glNormal3d(xN1,yN1,0);
				glVertex3d(x1 ,y1 , j*inc);
				glNormal3d(xN2,yN2,0);
				glVertex3d(x2,y2,j*inc);
				glNormal3d(xN2,yN2,0);
				glVertex3d(x2,y2,(j+1)*inc);
				glNormal3d(xN1,yN1,0);
				glVertex3d(x1 ,y1 , (j+1)*inc);

			}

			glEnd();
		}
		
		x1 = x2;
		y1 = y2;

		a+=da;

		x2=cos(a*myPi/180);
		y2=sin(a*myPi/180);
	}	



}