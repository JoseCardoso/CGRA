#include "LineTool.h"

void LineTool::mousePressed(int x, int y)
{
	// Reset start coordinates and active (current) coordinates
	sx=x;
	sy=y;
	currx=x;
	curry=y;

	// Activate XOR mode with inverted color to enable rubber-banding
	canvas->setXORMode();
	canvas->setColor(255);

	// Draw first line (one pixel)
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawLine(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawLine(sx,sy,currx,curry);
}

void LineTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawLine(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawLine(sx,sy,x,y);
}


void LineTool::MidPoint(int X0, int Y0, int X1, int Y1, bool octant)
{ 
	int a, b, d, inc1, inc2, x, y;

	a = X1 - X0;
	b = Y1 - Y0;
	inc2 = 2*b;
	d = inc2 - a; // d = 2*b – a;
	inc1 = d - a; // inc1 = 2*(b-a);
	x = X0; y=Y0;

	for(int i=X0; i<X1; i++)
	{ 
		if(octant)
			canvas->setPixel(i,y);
		else
			canvas->setPixel(y,i);
		if (d >= 0)
		{ 
			y=y+1; 
			d=d+inc1; 
		}
		else
			d=d+inc2; 

	}
}



void LineTool::MidPoint2(int X0, int Y0, int X1, int Y1, bool octant)
{ 
	int a, b, d, inc1, inc2, x, y;

	a = X1 - X0;
	b = Y1 - Y0;
	inc2 = 2*b;
	d = inc2 + a; // d = 2*b – a;
	inc1 = d + a; // inc1 = 2*(b-a);
	x = X0; y=Y0;

	for(int i=X0; i<X1; i++)
	{ 
		if(octant)
			canvas->setPixel(i,y);
		else
			canvas->setPixel(y,i);
		if (d >= 0)
		{ 
			y=y-1; 
			d=d-inc1; 
		}
		else
			d=d-inc2; 

	}
}


void LineTool::drawLine(int xi, int yi, int xf, int yf)
{
	// draws a line; 
	// simple flawed version, only draws in quadrants 1 and 4, 
	// and iterates over x, meaning there will be gaps on octants 2 and 7
	// where abs(delta y) > abs(delta x)
	/*
	float m;
	if (xf!=xi)
	m=(float) (yf-yi)/(float)(xf-xi);
	else
	m=0;

	for (int x=xi;x<=xf;x++)
	canvas->setPixel(x,yi+(x-xi)*m);
	*/


	if(xi == xf)
		for(int i=yi; i<yf; i++)
			canvas->setPixel(xi,i);
	else if(yi == yf)
	{
		for(int i=xi; i<xf; i++)
			canvas->setPixel(i,yi);
	}
	else if( xi <xf && yi < yf)//primeiro quadrante
		if((double)(yf-yi)/(xf-xi) <= (double)1)
			MidPoint( xi, yi, xf, yf,true);
		else
			MidPoint(yi,xi, yf,xf,false);
	else if(xi >xf &&  yi > yf)//terceiro quadrante
	{
		if((double)abs(yf-yi)/abs(xi-xf) > (double)1)
			MidPoint(yf,xf, yi,xi,false);
		else
			MidPoint( xf, yf, xi, yi,true);
	}
	else if(xi >xf &&  yi < yf)//segundo quadrante
	{
		if((double)abs(yf-yi)/abs(xi-xf) < (double)1)
			MidPoint2( xf, yf, xi, yi,true);
		else
			MidPoint2(yi,xi, yf,xf,false);
	}
	else//quarto quadrante
		if((double)abs(yf-yi)/abs(xi-xf) < (double)1)
			MidPoint2( xi, yi, xf, yf,true);
		else
			MidPoint2(yf,xf, yi,xi,false);
}