#ifndef _CIRCLETOOL_H_
#define _CIRCLETOOL_H_

#include "CanvasTool.h"
#include <cmath>

class CircleTool : public CanvasTool
{
public:
	CircleTool(CGFcanvas *cnv):CanvasTool(cnv){};

	virtual void mousePressed(int x, int y);
	virtual void mouseDragged(int x, int y);
	virtual void mouseReleased(int x, int y);

	virtual void drawCircle(int xi, int yi, int xf, int yf);
	void MidPoint(int xi, int yi,int R,bool octant);
	int sx, sy, currx, curry;
};

#endif
