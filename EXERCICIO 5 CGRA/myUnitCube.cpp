#include "myUnitCube.h"


void myUnitCube::drawNoTexture()
{
	glPushMatrix();
	glTranslated(-0.5,-0.5,-0.5);

	//face de tras
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(-1,0,0);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glVertex3d(0,0,0);
		glVertex3d(1,0,0);
		glVertex3d(1,1,0);
		glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();


	//face da frente
	glPushMatrix();
	glTranslated(0,0,1);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glVertex3d(0,0,0);
		glVertex3d(1,0,0);
		glVertex3d(1,1,0);
		glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();


	//face de baixo
	glPushMatrix();
	glRotated(90,1,0,0);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glVertex3d(0,0,0);
		glVertex3d(1,0,0);
		glVertex3d(1,1,0);
		glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();

	//face de cima
	glPushMatrix();
	glRotated(-90,1,0,0);
	glTranslated(0,-1,1);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glVertex3d(0,0,0);
		glVertex3d(1,0,0);
		glVertex3d(1,1,0);
		glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();



	//face da esquerda
	glPushMatrix();
	glRotated(-90,0,1,0);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glVertex3d(0,0,0);
		glVertex3d(1,0,0);
		glVertex3d(1,1,0);
		glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();

	//face da direita
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(-1,0,1);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glVertex3d(0,0,0);
		glVertex3d(1,0,0);
		glVertex3d(1,1,0);
		glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();
	glPopMatrix();


}

void myUnitCube::drawTextures()
{
	glPushMatrix();
	glTranslated(-0.5,-0.5,-0.5);

	//face de tras
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(-1,0,0);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glTexCoord2d(0,0);glVertex3d(0,0,0);
		glTexCoord2d(1,0);glVertex3d(1,0,0);
		glTexCoord2d(1,1);glVertex3d(1,1,0);
		glTexCoord2d(0,1);glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();


	//face da frente
	glPushMatrix();
	glTranslated(0,0,1);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glTexCoord2d(0,0);glVertex3d(0,0,0);
		glTexCoord2d(1,0);glVertex3d(1,0,0);
		glTexCoord2d(1,1);glVertex3d(1,1,0);
		glTexCoord2d(0,1);glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();


	//face de baixo
	glPushMatrix();
	glRotated(90,1,0,0);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glTexCoord2d(0,0);glVertex3d(0,0,0);
		glTexCoord2d(1,0);glVertex3d(1,0,0);
		glTexCoord2d(1,1);glVertex3d(1,1,0);
		glTexCoord2d(0,1);glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();

	//face de cima
	glPushMatrix();
	glRotated(-90,1,0,0);
	glTranslated(0,-1,1);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glTexCoord2d(0,0);glVertex3d(0,0,0);
		glTexCoord2d(1,0);glVertex3d(1,0,0);
		glTexCoord2d(1,1);glVertex3d(1,1,0);
		glTexCoord2d(0,1);glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();



	//face da esquerda
	glPushMatrix();
	glRotated(-90,0,1,0);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glTexCoord2d(0,0);glVertex3d(0,0,0);
		glTexCoord2d(1,0);glVertex3d(1,0,0);
		glTexCoord2d(1,1);glVertex3d(1,1,0);
		glTexCoord2d(0,1);glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();

	//face da direita
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(-1,0,1);
	glBegin(GL_QUADS);
		glNormal3d(0,0,1);
		glTexCoord2d(0,0);glVertex3d(0,0,0);
		glTexCoord2d(1,0);glVertex3d(1,0,0);
		glTexCoord2d(1,1);glVertex3d(1,1,0);
		glTexCoord2d(0,1);glVertex3d(0,1,0);
	glEnd();
	glPopMatrix();
	glPopMatrix();


}

