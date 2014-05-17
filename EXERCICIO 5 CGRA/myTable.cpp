#include "myTable.h"



void myTable:: draw(CGFappearance *legs , CGFappearance *tampo)
{
	drawLegs(legs);
	drawTampo(tampo);
}




void myTable:: drawLegs(CGFappearance *legs)
{

	myUnitCube perna1, perna2, perna3, perna4;
	
	legs->apply();

	glPushMatrix(); // transformações para todas asnpernas
	glScaled(0.3,3.5,0.3);
	glTranslated(-5,0.5,-3);

	//perna1
	glPushMatrix();
	perna1.drawNoTexture();
	glPopMatrix();

	//perna2
	glPushMatrix();
	glTranslated(10,0,0);
	perna2.drawNoTexture();
	glPopMatrix();

	//perna3
	glPushMatrix();
	glTranslated(0,0,6);
	perna3.drawNoTexture();
	glPopMatrix();

	//perna4
	glPushMatrix();
	glTranslated(10,0,6);
	perna4.drawNoTexture();
	glPopMatrix();

	glPopMatrix(); //Fecha as Pernas

}

void myTable::drawTampo(CGFappearance *tamp)
{

	glPushMatrix();
	myUnitCube *tampo = new myUnitCube();
	glTranslated(0,3.5,0);
	glScaled(5,0.3,3);
	tamp->apply();
	tampo->drawTextures();
	glPopMatrix();


}