#ifndef MY_CLOCKHAND
#define MY_CLOCKHAND

#include "CGFobject.h"




class myClockHand : public CGFobject {

	float angle;

	public:
		myClockHand();
		void draw();
		void setAngle (float angle);
		float getAngle() const;

};



#endif
