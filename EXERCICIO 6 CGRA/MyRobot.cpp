#include "MyRobot.h"

myRobot :: myRobot( int stacks)
{	this->stacks = stacks;
}


void myRobot :: draw()
{
	glPushMatrix();
	glRotated(90,0,1,0);
	drawComponent();
	glPopMatrix();

	
	glPushMatrix();
	glRotated(180,0,1,0);
	drawComponent();
	glPopMatrix();
	
	glPushMatrix();
	glRotated(-90,0,1,0);
	drawComponent();
	glPopMatrix();
	
	
	drawComponent();
}

void myRobot :: drawComponent()
{
	float alpha = -45 * PI /180;//angulo do 1º vertice
	float incA = 30 * PI /180;//metade de cada angulo 

	vector <vector<double >> coordx, coordy,coordz, normalx, normalz;

	coordx.resize(stacks);
	coordy.resize(stacks);
	coordz.resize(stacks);
	normalx.resize(stacks);
	normalz.resize(stacks);

	for (int i = 0 ; i < stacks; i++){
		coordx[i].resize(4);
		coordy[i].resize(4);
		coordz[i].resize(4);
		normalx[i].resize(4);
		normalz[i].resize(4);
	}

	double normalize = sqrt(1+0.25*0.25);
	for (int i = 0 ; i < 4 ; i ++ )
	{
		coordx[0][i] = 0.5*tan(alpha + i*incA);
		coordy[0][i] = 0;
		coordz[0][i] = 0.5;
		
		normalx[0][i] = 0;
		normalz[0][i] = 1;

		coordx[stacks-1][i] = 0.25*sin(alpha + incA*i); 
		coordy[stacks-1][i] = 1;
		coordz[stacks-1][i] =  0.25*cos(alpha + incA*i);

		normalx[stacks-1][i] = coordx[stacks-1][i]/normalize;
		normalz[stacks-1][i] = coordz[stacks-1][i]/normalize;

		double incX = (double) (coordx[stacks-1][i] - coordx[0][i])/stacks;
		double incZ = (double) (coordz[stacks-1][i] - coordz[0][i])/ stacks;

		double incNx = normalx[stacks-1][i] /stacks;
		
		double incNz = (normalz[stacks-1][i] -1) /stacks;

		for (int j = 1 ; j < stacks - 1 ; j++) // começa na 2 linha a contar por baixo e termina na penultima
		{
			coordx[j][i] = (double) incX + coordx[j-1][i];
			coordy[j][i] = (double) j/stacks;
			coordz[j][i] = (double) incZ + coordz[j-1][i];
			//coordz[j][i] = (double) coordz[0][i] + (coordz[stacks-1][i] - coordz[0][i])*((coordx[j][i] - coordx[0][i])/(coordx[stacks-1][i] - coordx[0][i]));
			normalx[j][i] = j*incNx;//confirmar depois
			normalz[j][i] = j*incNz;


		}
	}


	for (unsigned int i = 0 ; i < stacks-1 ; i++)
	{

		for (unsigned int j = 0 ; j < 3 ; j++)
		{
			glBegin(GL_QUADS);
			
			glNormal3d(normalx[i][j],0,normalz[i][j]); 
			glVertex3d(coordx[i][j] , coordy[i][j] , coordz[i][j]);
			
			glNormal3d(normalx[i][j+1],0,normalz[i][j+1]); 
			glVertex3d(coordx[i][j+1] , coordy[i][j+1] , coordz[i][j+1]);
			
			glNormal3d(normalx[i+1][j+1],0,normalz[i+1][j+1]);	
			glVertex3d(coordx[i+1][j+1] , coordy[i+1][j+1] , coordz[i+1][j+1]);
			
			glNormal3d(normalx[i+1][j],0,normalz[i+1][j]);	
			glVertex3d(coordx[i+1][j] , coordy[i+1][j] , coordz[i+1][j]);
			glEnd();
		}

	}



}

