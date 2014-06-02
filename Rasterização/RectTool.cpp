#include "RectTool.h"

void RectTool::mousePressed(int x, int y)
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
	drawRect(sx,sy,currx,curry);
}

void RectTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawRect(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawRect(sx,sy,currx,curry);
}

void RectTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawRect(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawRect(sx,sy,x,y);
}



void RectTool::drawRect(int xi, int yi, int xf, int yf)
{
	// draws a line; 
	// simple flawed version, only draws in quadrants 1 and 4, 
	// and iterates over x, meaning there will be gaps on octants 2 and 7
	// where abs(delta y) > abs(delta x)
	/*	int x,y;


	*/
	int x ,y;

	if(xi > xf)
	{
		x = xf;
		xf = xi;
		xi = x;
	}
	else
		x = xi;


	for (;x<=xf;x++)
	{
		canvas->setPixel(x,yi);
		canvas->setPixel(x, yf);
	}

	if(yi > yf)
	{
		y = yf;
		yf = yi;
	}
	else
		y= yi;

	for (;y<=yf;y++)
	{
		canvas->setPixel(xi,y);
		canvas->setPixel(xf,y);
	}


}