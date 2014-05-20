#pragma once

#include "CGFobject.h"
#include "CGFappearance.h"
//h� uma fun��o para calcular as distancias

class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void drawCentered(bool window);
	void setHeight(double h);
	void setWidth(double w);
	void drawWindowedWall();
	void drawWindow();
	void drawFloor(int sizex, int sizey);

	//glTextlevelparameter
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	double height, width;
};

