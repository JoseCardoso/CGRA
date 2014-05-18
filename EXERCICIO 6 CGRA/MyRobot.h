#ifndef MY_ROBOT	
#define MY_ROBOT

#include "CGFobject.h"
#include <math.h>
#include <vector>

using namespace std;

#define PI 3.1415926536



class myRobot : public CGFobject {
	
	int stacks;
	double teta; //angulo em rela��o a z de rota�ao ao premir a tecla
	double x; //coordenadas para calcular avan�o e recuo
	double z; //

	public:
		myRobot(int stacks);
		void draw();
		void drawComponent(int side);
		void processKeyboard(unsigned char key);

};



#endif
