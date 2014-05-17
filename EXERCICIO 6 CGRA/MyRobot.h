#ifndef MY_ROBOT	
#define MY_ROBOT

#include "CGFobject.h"
#include <math.h>
#include <vector>

using namespace std;

#define PI 3.1415926536



class myRobot : public CGFobject {
	
	int stacks;

	public:
		myRobot(int stacks);
		void draw();
		void drawComponent(int side);

};



#endif
