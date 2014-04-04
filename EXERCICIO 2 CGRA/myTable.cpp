#include "myTable.h"


void myTable:: draw()
{
	float brown[4]={102,51,0,1};
	float difBrown[3] = {0.2,0.1, 0.0};
	float specBrown[3] = {0.1, 0.0, 0.0};
	float shininessBrown = 120.f;

	float silver[4]={192,192,192,1};
	float difSilver[3] = {0.5,0.5, 0.5};
	float specSilver[3] = {1, 1, 1};
	float shininessSilver = 120.f;
	CGFappearance* material1 = new CGFappearance(brown, difBrown , specBrown , shininessBrown);
	CGFappearance* material2 = new CGFappearance(silver, difSilver , specSilver , shininessSilver);	
	material2->apply();
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
	
	material1->apply();
	myUnitCube tampo;
	glTranslated(0,3.5,0);
	glScaled(5,0.3,3);
	tampo.draw();
	glPopMatrix();
	

}
