#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"
#include <cmath>



class myCylinder : public CGFobject {
	
	int slices;
	int stacks;
	bool smooth;

	public:
		myCylinder(int slices, int stacks, bool smooth);
		void draw();

};



#endif
