#pragma once

#include "CGFobject.h"
#include "CGFappearance.h"
//há uma função para calcular as distancias

class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void drawCentered();
	void setHeight(double h);
	void setWidth(double w);

	//glTextlevelparameter
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	double height, width;
};

