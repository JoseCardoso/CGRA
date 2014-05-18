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

	double inc = ((texW*height/width)/texH);
	double inc2 = ((texH*width/height)/texW);

	double incH = (inc - 1) / 2;

	double incW = (inc2 - 1) / 2;

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		if (!window)
			glTexCoord2d(bx/ (_numDivisions*1.0) ,-incH);
		else
			glTexCoord2d((bx/ (_numDivisions*1.0)) -incW ,-incH);
		glVertex3f(bx, 0, 0);

		for (int bz = 0; bz<_numDivisions; bz++)
		{
			if(!window)
				glTexCoord2d((bx+1)/(_numDivisions*1.0)  ,( bz/(_numDivisions*1.0)) *inc  - incH);
			else
				glTexCoord2d(((bx+1)/(_numDivisions*1.0))*inc2 -incW  ,( bz/(_numDivisions*1.0)) *inc  - incH);
			glVertex3f(bx + 1, 0, bz);
			
			if(!window)
				glTexCoord2d(bx/(_numDivisions*1.0)  ,((bz+1)/(_numDivisions*1.0)) *inc - incH);
			else
				glTexCoord2d((bx/(_numDivisions*1.0))*inc2 -incW  , ((bz+1)/(_numDivisions*1.0)) *inc  - incH);
			glVertex3f(bx, 0, bz + 1);
		}
		if(!window)
			glTexCoord2d((bx+ 1) /(_numDivisions*1.0)  , inc + incH);
		else
			glTexCoord2d(((bx+ 1) /(_numDivisions*1.0))*inc2 - incW  , inc + incH);
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

void Plane:: setHeight(double h)
{
	height = h;
}
void Plane:: setWidth(double w)
{
	width = w;
}
