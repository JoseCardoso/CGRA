#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.2,0.2,0.2,1.0};
// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0.0, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for slide texture
float ambSlides[3] = {0.2, 0.2, 0.2};
float difSlides[3] = {0.8, 0.8, 0.8};
float specSlides[3] = {0.1, 0.1, 0.1};
float shininessSlides = 10.f;

// Coefficients for board texture
float ambBoard[3] = {0.2, 0.2, 0.2};
float difBoard[3] = {0.3, 0.3, 0.3};
float specBoard[3] = {0.6, 0.6, 0.6};
float shininessBoard = 200.f;



float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::init() 
{
	sceneVar=0;
	light0On = 1;
	light1On = 1;
	light2On = 0;
	light3On = 0;
	textureSelector = 1;
	wire = 0;
	landscapeSelector = 0;

	clockAnimation = true;
	// Enables lighting computations
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  

	// Declares and enables two lights, with null ambient component

	glShadeModel(GL_SMOOTH);


	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	if (light0On == 0)
		light0->disable();
	else
		light0->enable();


	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	if (light1On == 0)
		light1->disable();
	else
		light1->enable();


	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);

	if (light2On == 0)
		light2->disable();
	else
		light2->enable();



	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setSpecular(yellow);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(1);

	if (light3On == 0)
		light3->disable();
	else
		light3->enable();




	// Uncomment below to enable normalization of lighting normal vectors
	// glEnable (GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();
	floor = new Plane();
	clock = new myClock();
	cylinder = new myCylinder(10,10, true);
	cylinder1 = new myCylinder(10,10,false);
	skybox = new myCylinder(60,10,true);
	robot = new myRobot(10);

	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);

	//Declares materials
	materialA = new CGFappearance(ambientNull,difA,specA,shininessA);
	materialB = new CGFappearance(ambientNull,difB,specB,shininessB);

	//Declares Textures
	tableAppearence = new CGFappearance(ambientNull,difA,specA,shininessA);
	tableAppearence->setTexture("table.png");
	tableAppearence->setTextureWrap(GL_REPEAT,GL_REPEAT);

	slidesAppearence = new CGFappearance(ambientNull,difSlides,specSlides,shininessSlides);
	slidesAppearence->setTexture("slides.png");
	slidesAppearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	boardAppearence = new CGFappearance(ambientNull,difBoard,specBoard,shininessBoard);
	boardAppearence->setTexture("board.png");
	boardAppearence->setTextureWrap(GL_CLAMP,GL_CLAMP);


	windowAppearence = new CGFappearance(ambientNull , difA , specA , shininessA);
	windowAppearence->setTexture("window.png");
	windowAppearence->setTextureWrap(GL_CLAMP, GL_CLAMP);

	floorAppearence = new CGFappearance(ambientNull, difA, specA , shininessA);
	floorAppearence->setTexture("floor.png");
	floorAppearence->setTextureWrap(GL_REPEAT, GL_REPEAT);

	clockAppearence = new CGFappearance (ambientNull , difA , specA, shininessA);
	clockAppearence->setTexture("clock.png");
	clockAppearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	robotAppearence = new CGFappearance (ambientNull, difA , specA, shininessA);
	robotAppearence->setTexture("robot1.jpg");
	robotAppearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	robot2Appearence = new CGFappearance (ambientNull, difA , specA, shininessA);
	robot2Appearence->setTexture("robot2.jpg");
	robot2Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	
	robot3Appearence = new CGFappearance (ambientNull, difA , specA, shininessA);
	robot3Appearence->setTexture("robot3.png");
	robot3Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	
	robot4Appearence = new CGFappearance (ambientNull, difA , specA, shininessA);
	robot4Appearence->setTexture("robot4.png");
	robot4Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	
	robot5Appearence = new CGFappearance (ambientNull, difA , specA, shininessA);
	robot5Appearence->setTexture("robot5.jpg");
	robot5Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	landscapeAppearence = new CGFappearance (globalAmbientLight, difA , specA, shininessA);
	landscapeAppearence->setTexture("panoramic.jpg");
	landscapeAppearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	landscape2Appearence = new CGFappearance (globalAmbientLight, difA , specA, shininessA);
	landscape2Appearence->setTexture("panoramic2.jpg");
	landscape2Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	
	landscape3Appearence = new CGFappearance (globalAmbientLight, difA , specA, shininessA);
	landscape3Appearence->setTexture("panoramic3.jpg");
	landscape3Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	
	landscape4Appearence = new CGFappearance (globalAmbientLight, difA , specA, shininessA);
	landscape4Appearence->setTexture("panoramic4.jpg");
	landscape4Appearence->setTextureWrap(GL_CLAMP,GL_CLAMP);

	setUpdatePeriod(100);
}

void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();


	light0->draw();
	light0->disable();
	if (light0On != 0)
		light0->enable();

	light1->draw();
	light1->disable();
	if (light1On != 0)
		light1->enable();

	light2->draw();
	light2->disable();
	if (light2On != 0)
		light2->enable();

	light3->draw();
	light3->disable();
	if (light3On != 0)
		light3->enable();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//First Table
	glPushMatrix();
	glTranslated(5,0,8);
	table->draw(materialA, tableAppearence);
	glPopMatrix();
	/*
	//Second Table
	glPushMatrix();
	glTranslated(12,0,8);
	table->draw(materialA, tableAppearence);
	glPopMatrix();
	*/
	materialA->apply();
	//Floor
	glPushMatrix();
	floorAppearence->apply();
	glTranslated(7.5,0,7.5);
	glScaled(15,0.2,15);
	floor->drawFloor(10, 12);
	glPopMatrix();

	//LeftWall
	glPushMatrix();
	windowAppearence->apply();
	wall->drawWindowedWall();
	/*
	glTranslated(0,4,7.5);
	glRotated(-90.0,0,0,1);
	glScaled(8,0.2,15);
	wall->setHeight(15);
	wall->setWidth(8);
	windowAppearence->apply();
	wall->drawCentered(true);*/
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
	glTranslated(7.5,4,0);
	glRotated(90.0,1,0,0);
	glScaled(15,0.2,8);
	materialA->apply();
	wall->draw();
	glPopMatrix();


	// Board A
	glPushMatrix();
	glTranslated(4,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	boardA->setHeight(BOARD_HEIGHT);
	boardA->setWidth(BOARD_WIDTH);
	glRotated(90.0,1,0,0);
	slidesAppearence->apply();
	boardA->drawCentered(false);
	glPopMatrix();

	//PlaneB
	glPushMatrix();
	boardAppearence->apply();
	glTranslated(10.5,4,0.2);
	glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
	boardB->setHeight(BOARD_HEIGHT);
	boardB->setWidth(BOARD_WIDTH);
	glRotated(90.0,1,0,0);
	boardAppearence->apply();
	boardB->drawCentered(false);
	glPopMatrix();

	//cylinder
	materialA->apply();
	glPushMatrix();
	glScaled(1,8,1);
	glTranslated(1,0,2);
	glRotated(-90, 1,0,0);
	cylinder->draw();
	glPopMatrix();


	glPushMatrix();
	glScaled(1,8,1);
	glTranslated(14,0,2);
	glRotated(-90, 1,0,0);
	cylinder1->draw();
	glPopMatrix();


	//clock
	glPushMatrix();
	clockAppearence->apply();
	glTranslated(7,8,0);
	clock->draw();
	glPopMatrix();

	//robot

	glPushMatrix();
	glTranslated(4,0,4);
	if (wire){
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	robot->draw();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else{
	setRobotTexture();
	robot->draw();
	}
	glPopMatrix();


	//skybox

	glPushMatrix();
	glTranslated(5,-7.5,7.5);
	glScaled(30,30,30);
	glRotated(-90,1,0,0);
	setLandscape();
	skybox->drawSky();
	glPopMatrix();
	// ---- END Primitive drawing section


	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}


void LightingScene::update(unsigned long millis)
{
	if(clockAnimation)
		clock->update(millis);

}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}

void LightingScene::processKeyboard(unsigned char key)
{

	robot->processKeyboard(key);
}

int LightingScene:: pauseResetClock()
{
	if(clockAnimation)
	{
		clockAnimation = !clockAnimation;
		return 0;
	}
	else
	{
		clock->resetClock();
		clockAnimation = !clockAnimation;
		return 1;
	}
}


void LightingScene:: setRobotTexture()
{
	switch(textureSelector)
	{

	case 1:
		robotAppearence->apply();
		break;
	case 2:
		robot2Appearence->apply();
		break;
	case 3:
		robot3Appearence->apply();
		break;
	case 4:
		robot4Appearence->apply();
		break;	
	case 5:
		robot5Appearence->apply();
		break;
	}
	
}


void LightingScene:: setLandscape()
{
	switch(landscapeSelector)
	{

	case 1:
		landscapeAppearence->apply();
		break;
	case 2:
		landscape2Appearence->apply();
		break;
	case 3:
		landscape3Appearence->apply();
		break;
	case 4:
		landscape4Appearence->apply();
		break;	
	}

}