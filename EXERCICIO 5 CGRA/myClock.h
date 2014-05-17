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
	public:
		myClock();
		void draw();
		void update(unsigned long);

};



#endif
