#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myClock.h"
#include "myClockHand.h"
#include "myCylinder.h"
#include "MyRobot.h"
#include "TPinterface.h"

class LightingScene : public CGFscene
{
	 bool clockAnimation;
public:
	int sceneVar;
	int light0On, light1On, light2On, light3On;
	int textureSelector;
	int wire;
	void init();
	void display();
	void update(unsigned long millis);
	void processKeyboard(unsigned char key);
	int pauseResetClock();
	void setRobotTexture();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;


	myTable* table;
	myCylinder* cylinder;
	myCylinder* cylinder1;
	myCylinder* skybox;
	myClock* clock;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	myRobot* robot;
	CGFappearance* materialA;
	CGFappearance* materialB;

	CGFappearance* floorAppearence;
	CGFappearance* tableAppearence;
	CGFappearance* slidesAppearence;
	CGFappearance* wallAppearence;
	CGFappearance* boardAppearence;
	CGFappearance* windowAppearence;
	CGFappearance* clockAppearence;
	CGFappearance* landscapeAppearence;

	CGFappearance* robotAppearence;
	CGFappearance* robot2Appearence;
	CGFappearance* robot3Appearence;
	CGFappearance* robot4Appearence;
	CGFappearance* robot5Appearence;

	
	~LightingScene();
};

#endif