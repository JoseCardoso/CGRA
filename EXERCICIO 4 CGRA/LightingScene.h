#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;


	myTable* table;
	myCylinder* cylinder;
	myCylinder* cylinder1;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;

	CGFappearance* floorAppearence;
	CGFappearance* tableAppearence;
	CGFappearance* slidesAppearence;
	CGFappearance* wallAppearence;
	CGFappearance* boardAppearence;
	CGFappearance* windowAppearence;
	
	~LightingScene();
};

#endif