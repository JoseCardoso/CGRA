#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGFobject.h"
#include "myCylinder.h"
#include "myClockHand.h"



class myClock : public CGFobject {

	myCylinder *clock;	
	myClockHand* segundos;
	myClockHand* minutos;
	myClockHand* horas;
	unsigned long myTime; // guarda o tempo em que o relogio actualizou pela ultima vez, inicia a 0
	public:
		myClock();
		void draw();
		void update(unsigned long);

};



#endif
