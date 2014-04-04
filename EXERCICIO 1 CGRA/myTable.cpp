#include "myTable.h"



void myTable:: draw()
{

	myUnitCube perna1, perna2, perna3, perna4;
	
	glPushMatrix(); // transformações para todas asnpernas
	
	glScaled(0.3,3.5,0.3);
	glTranslated(-5,0.5,-3);

	//perna1
	glPushMatrix();
	perna1.draw();
	glPopMatrix();

	//perna2
	glPushMatrix();
	glTranslated(10,0,0);
	perna2.draw();
	glPopMatrix();

	//perna3
	glPushMatrix();
	glTranslated(0,0,6);
	perna3.draw();
	glPopMatrix();

	//perna4
	glPushMatrix();
	glTranslated(10,0,6);
	perna4.draw();
	glPopMatrix();

	glPopMatrix(); //Fecha as Pernas

	glPushMatrix();
	myUnitCube tampo;
	glTranslated(0,3.5,0);
	glScaled(5,0.3,3);
	tampo.draw();
	glPopMatrix();

}
