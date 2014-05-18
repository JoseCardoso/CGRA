#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	testVar=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);


			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			
			unsigned char toUpperKey = toupper(key);
			((LightingScene *) scene)->toggleSomething(toUpperKey);
	
}

void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Group", 1);
	
	// You could also pass a reference to a variable from the scene class, if public

	addCheckboxToPanel(varPanel, "light 1", &(((LightingScene*) scene)->light0On), 1);
	
	addCheckboxToPanel(varPanel, "light 2", &(((LightingScene*) scene)->light1On), 2);
	
	addCheckboxToPanel(varPanel, "light 3", &(((LightingScene*) scene)->light2On), 3);
	
	addCheckboxToPanel(varPanel, "light 4", &(((LightingScene*) scene)->light3On), 4);

	
	GLUI_Button* pauseClock =  addButtonToPanel(varPanel, "Pause Clock", 5);
	//pauseClock->
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf ("New Val 1(interface): %d\n",testVar);
			break;
		};

		case 2:
		{
			printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			break;
		};
	};
}

