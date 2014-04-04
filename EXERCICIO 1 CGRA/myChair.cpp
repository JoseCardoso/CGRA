#include "myChair.h"



void myChair:: draw()
{

	myUnitCube perna1, perna2, perna3, perna4;

	glPushMatrix();//escalamento para a cadeira ficar com um tamanho maior
	glScaled(1.2,1.2,1.2);

	glPushMatrix(); // transformações para todas as pernas
	
	glScaled(0.3,1.75,0.3);
	glTranslated(-2,0.5,-2);

	//perna1
	glPushMatrix();
	perna1.draw();
	glPopMatrix();

	//perna2
	glPushMatrix();
	glTranslated(4,0,0);
	perna2.draw();
	glPopMatrix();

	//perna3
	glPushMatrix();
	glTranslated(0,0,4);
	perna3.draw();
	glPopMatrix();

	//perna4
	glPushMatrix();
	glTranslated(4,0,4);
	perna4.draw();
	glPopMatrix();

	glPopMatrix(); //Fecha as Pernas

	glPushMatrix();//tampo e encosto
	

	//encosto
	glPushMatrix();
	myUnitCube encosto;
	glTranslated(-0.6,2.7,0);
	glScaled(0.3,2,1.5);
	encosto.draw();
	glPopMatrix();

	glPushMatrix();
	myUnitCube tampo;
	glTranslated(0,1.75,0);
	glScaled(1.5,0.3,1.5);
	tampo.draw();
	glPopMatrix(); 

	glPopMatrix();//fecha o tampo e encosto

	glPopMatrix(); //acabar escalamento
}
