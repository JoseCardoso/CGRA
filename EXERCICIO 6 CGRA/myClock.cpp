#include "myClock.h"
#include <time.h>

using namespace std;

myClock :: myClock()
{	
	segundos = new myClockHand();
	minutos = new myClockHand();
	horas = new myClockHand();
	clock = new myCylinder(12, 10 ,true);
	segundos->setAngle(90);
	minutos->setAngle(180);
	horas->setAngle(-90);
}


void myClock ::draw()
{
	
	//clock hands segundos

	glPushMatrix();
	glTranslated(0,0,0.2);
	segundos->draw();
	glPopMatrix();

	//clock hands minutos

	glPushMatrix();
	glTranslated(0,0,0.21);
	glScaled(0.8,0.8,1);
	minutos->draw();
	glPopMatrix();

	//clock hands horas

	glPushMatrix();
	glTranslated(0,0,0.22);
	glScaled(0.5,1.5,1);
	horas->draw();
	glPopMatrix();

	glPushMatrix();
	glScaled(1,1,0.1);
	clock->draw();
	glPopMatrix();
}

void myClock:: update(unsigned long millis)
{
//segundos 1/60 minutos  1/60/60 horas 1/60/60/60


	float inc = (float)  360 *millis / 60000; 
	
	segundos->setAngle(segundos->getAngle() - inc);

	minutos->setAngle(minutos->getAngle() - inc/60);

	horas ->setAngle(horas->getAngle() - inc/3600);
	
}