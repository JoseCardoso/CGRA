#include "myUnitCube.h"


void myUnitCube::draw()
{
	glPushMatrix();
	glTranslated(-0.5,-0.5,-0.5);

	//face de tras
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(-1,0,0);
	glNormal3d(0,0,1);
	glRectd(0,0,1,1);
	glPopMatrix();
	

	//face da frente
	glPushMatrix();
	glTranslated(0,0,1);
	glNormal3d(0,0,1);
	glRectd(0,0,1,1);
	glPopMatrix();


	//face de baixo
	glPushMatrix();
	glRotated(90,1,0,0);
	glNormal3d(0,0,1);
	glRectd(0,0,1,1);
	glPopMatrix();

	//face de cima
	glPushMatrix();
	glRotated(-90,1,0,0);
	glTranslated(0,-1,1);
	glNormal3d(0,0,1);
	glRectd(0,0,1,1);
	glPopMatrix();



	//face da esquerda
	glPushMatrix();
	glRotated(-90,0,1,0);
	glNormal3d(0,0,1);
	glRectd(0,0,1,1);
	glPopMatrix();

	//face da direita
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(-1,0,1);
	glNormal3d(0,0,1);
	glRectd(0,0,1,1);
	glPopMatrix();
	glPopMatrix();


}