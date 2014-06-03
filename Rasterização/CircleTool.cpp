#include "CircleTool.h"

void CircleTool::mousePressed(int x, int y)
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
	drawCircle(sx,sy,currx,curry);
}

void CircleTool::mouseDragged(int x, int y)
{
	// Redraw previous line (in XOR mode, will invert the color of all pixels, effectively erasing it)
	drawCircle(sx,sy,currx,curry);

	// Update current coordinates
	currx=x;
	curry=y;

	// Draw new line
	drawCircle(sx,sy,currx,curry);
}

void CircleTool::mouseReleased(int x, int y)
{
	// Redraw previous line to erase it
	drawCircle(sx,sy,currx,curry);

	// Set normal mode and color to draw fianl line
	canvas->setNormalMode();
	canvas->setColor(0);

	// draw final line
	drawCircle(sx,sy,x,y);
}


void CircleTool::MidPoint(int xi, int yi,int R, bool octant)
{ 
	{
		int x, y, p, inc_E, inc_SE;
		x=0; y=R;
		p = 1-R;
		inc_E=3; inc_SE=5-2*R;
		canvas->setPixel(x+xi,y+yi);
		canvas->setPixel(-x+xi,y+yi);
		canvas->setPixel(x+xi,-y+yi);
		canvas->setPixel(-x+xi,-y+yi);
		while(y > x)
		{
			if (p<0)
			{ 
				p=p+inc_E;
				inc_E=inc_E+2;
				inc_SE=inc_SE+2;
				x++;
			}
			else
			{ 
				p=p+inc_SE;
				inc_E=inc_E+2;
				inc_SE=inc_SE +4;
				x++; y--;
			}
			canvas->setPixel(x+xi,y+yi);
			canvas->setPixel(-x+xi,y+yi);
			canvas->setPixel(x+xi,-y+yi);
			canvas->setPixel(-x+xi,-y+yi);
			canvas->setPixel(y+xi,x+yi);
			canvas->setPixel(-y+xi,x+yi);
			canvas->setPixel(y+xi,-x+yi);
			canvas->setPixel(-y+xi,-x+yi);
		}
	}
}


void CircleTool::drawCircle(int xi, int yi, int xf, int yf)
{
	
	int r = sqrt((xf-xi)*(xf-xi) + (yf-yi)*(yf-yi));
	MidPoint( xi,  yi, r,true);
	
}