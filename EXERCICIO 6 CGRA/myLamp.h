#ifndef MY_LAMP
#define MY_LAMP

#include "CGFobject.h"
#include <cmath>



class myLamp : public CGFobject {
	
	int slices;
	int stacks;
	bool smooth;

	public:
		myLamp(int slices, int stacks, bool smooth);
		void draw();

};



#endif
