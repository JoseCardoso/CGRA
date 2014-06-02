#ifndef _LINETOOL_H_
#define _LINETOOL_H_

#include "CanvasTool.h"
#include <cmath>

class LineTool : public CanvasTool
{
public:
	LineTool(CGFcanvas *cnv):CanvasTool(cnv){};

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual void drawLine(int xi, int yi, int xf, int yf);
	void MidPoint(int X0, int Y0, int X1, int Y1,bool octant);
	void MidPoint2(int X0, int Y0, int X1, int Y1,bool octant);
	int sx, sy, currx, curry;
};

#endif
