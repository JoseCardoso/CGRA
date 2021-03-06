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
	int landscapeSelector;
	int wire;
	void init();
	void display();
	void update(unsigned long millis);
	void processKeyboard(unsigned char key);
	int pauseClock();
	int resetClock();
	void setRobotTexture();
	void setLandscape();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* dayLight;


	myTable* table;
	myCylinder* cylinder;
	myCylinder* cylinder1;
	myCylinder* skybox;
	myClock* clock;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	Plane* floor;
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
	CGFappearance* landscape2Appearence;
	CGFappearance* landscape3Appearence;
	CGFappearance* landscape4Appearence;

	CGFappearance* robotAppearence;
	CGFappearance* robot2Appearence;
	CGFappearance* robot3Appearence;
	CGFappearance* robot4Appearence;
	CGFappearance* robot5Appearence;

	
	~LightingScene();
};

#endif