#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}


Plane::~Plane(void)
{
}


void Plane::drawCentered(bool window)
{
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	//getting texture width
	int texW;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0 , GL_TEXTURE_WIDTH, &texW );
	//getting texture height
	int texH;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0 , GL_TEXTURE_HEIGHT, &texH);

	double numx , numx2,numz,numz2;
	double inc =(double) ((texW*height/width)/texH);
	double inc2 = (double) ((texH*width/height)/texW);
	double incH = (inc - 1) / 2;
	double incW = (inc2 - 1) *2.2;

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		numx = (float) bx/_numDivisions;
		numx2 = (float) (bx+1)/_numDivisions;

		glBegin(GL_TRIANGLE_STRIP);
		if (!window)
			glTexCoord2d(numx ,-incH);
		else
			glTexCoord2d((numx2-incW),1+incH);
		glVertex3d(bx, 0, 0);

		for (int bz = 0; bz<_numDivisions; bz++)
		{


			numz = (float)bz/_numDivisions;
			numz2 = (float) (bz+1)/_numDivisions;

			if(!window)
				glTexCoord2d(numx2 ,numz *inc  - incH);
			else
				glTexCoord2d(numx2-incW,numz*inc-incH);
			glVertex3d(bx + 1, 0, bz);
		/*	if(bx+1 == 2 && bz == 1)
			{
				glEnd();
				glBegin(GL_TRIANGLE_STRIP);
			}*/
			if(!window)
				glTexCoord2d(numx  ,numz2 *inc - incH);
			else
				glTexCoord2d(numx+incW,numz2*inc-incH);
			glVertex3d(bx, 0, bz + 1);


		}
		if(!window)
			glTexCoord2d(numx2  , inc + incH);
		else
			glTexCoord2d(numx+incW,0-incH);
		glVertex3d(bx +1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();
}

void Plane::draw()
{
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(bx/(_numDivisions*1.0) ,0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{	
			glTexCoord2d((bx+1)/(_numDivisions*1.0)  ,bz/(_numDivisions*1.0));
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d(bx/(_numDivisions*1.0)  ,(bz+1)/(_numDivisions*1.0));
			glVertex3f(bx, 0, bz + 1);

		}
		glTexCoord2d((bx+1)/(_numDivisions*1.0)  , 1);
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

}
void Plane::drawFloor(int sizex, int sizez)
{

	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(bx / _numDivisions, 0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2f((bx + 1) / _numDivisions * sizex, bz / _numDivisions * sizez);
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2f(bx / _numDivisions * sizex,(bz + 1) / _numDivisions * sizez);
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2f((bx + 1) / _numDivisions * sizex, sizez);
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();


}

void Plane:: setHeight(double h)
{
	height = h;
}

void Plane:: setWidth(double w)
{
	width = w;
}

void Plane::drawWindowedWall(){


	//right strip largura = 6 altura = 3  meio = 2
	//baixo
	glPushMatrix();
	glTranslated(0,1,2.75);
	glScaled(1,2,5.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);

	glTexCoord2d(-1,-1);
	glVertex3d(0,-0.5,-0.5);//canto inferior direito

	
	glTexCoord2d(0.025,-1);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(0.025, 0.025);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	
	glTexCoord2d(0.025,-1);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//meio
	glPushMatrix();
	glTranslated(0,4,2.75);
	glScaled(1,4,5.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(-1,0.025);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(-1,0.975);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(0.025,0.975);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(0.025,0.025);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//topo
	glPushMatrix();
	glTranslated(0,7,2.75);
	glScaled(1,2,5.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);
	glTexCoord2d(-1,0.975);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(-1,2);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(0.025,2);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(0.025,0.975);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//mid strip
	//baixo
	glPushMatrix();
	glTranslated(0,1,7.5);
	glScaled(1,2,4);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);

	glTexCoord2d(0.025,-1);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(0.025,0.025);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(0.975,0.025);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(0.975,-1);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();


	//topo
	glPushMatrix();
	glTranslated(0,7,7.5);
	glScaled(1,2,4);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);

	glTexCoord2d(0.025,0.975);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(0.025,2);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(0.975,2);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(0.975,0.975);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();


	//left strip
	//baixo
	glPushMatrix();
	glTranslated(0,1,12.25);
	glScaled(1,2,5.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);

	glTexCoord2d(0.975,-1);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(0.975,0.025);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(2,0.025);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(2,-1);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();

	//meio
	glPushMatrix();
	glTranslated(0,4,12.25);
	glScaled(1,4,5.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);

	glTexCoord2d(0.975,0.025);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(0.975,0.975);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(2,0.975);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(2,0.025);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslated(0,7,12.25);
	glScaled(1,2,5.5);
	glBegin(GL_QUADS);
	glNormal3d(1,0,0);

	glTexCoord2d(0.975,0.975);//canto inferior direito
	glVertex3d(0,-0.5,-0.5);

	glTexCoord2d(0.975,2);//canto superior direito
	glVertex3d(0,0.5,-0.5);

	glTexCoord2d(2,2);//canto superior esquerdo
	glVertex3d(0,0.5,0.5);

	glTexCoord2d(2,0.975);//canto inferior esquerdo
	glVertex3d(0,-0.5,0.5);
	glEnd();
	glPopMatrix();


}


