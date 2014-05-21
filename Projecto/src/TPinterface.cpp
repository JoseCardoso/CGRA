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
	((LightingScene *) scene)->processKeyboard(toUpperKey);
	
}

void TPinterface::initGUI()
{
	
	int* textureSelect = &(((LightingScene*) scene)->textureSelector);
	
	int* wire = &(((LightingScene*) scene)->wire);

	int* landscapeSelect = &(((LightingScene*) scene)->landscapeSelector);

	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Light:", 1);
	
	
	// You could also pass a reference to a variable from the scene class, if public

	addCheckboxToPanel(varPanel, "light 1", &(((LightingScene*) scene)->light0On), 1);
	
	addCheckboxToPanel(varPanel, "light 2", &(((LightingScene*) scene)->light1On), 2);
	
	addCheckboxToPanel(varPanel, "light 3", &(((LightingScene*) scene)->light2On), 3);
	
	addCheckboxToPanel(varPanel, "light 4", &(((LightingScene*) scene)->light3On), 4);

	addColumnToPanel(varPanel);
	
	GLUI_Button* pauseClock =  addButtonToPanel(varPanel, "Pause/Reset Clock", 5);
	
	addColumnToPanel(varPanel);


	GLUI_Listbox* textures = addListboxToPanel(varPanel, "Textures",textureSelect, 6);

	textures->add_item(1, "Default robot");
	textures->add_item(2, "Army robot");
	textures->add_item(3, "Groovy robot");
	textures->add_item(4, "Deformed robot");
	textures->add_item(5, "Fancy robot");

	GLUI_RadioGroup* wireFrameGroup = addRadioGroupToPanel(varPanel,wire, 7);
	addRadioButtonToGroup(wireFrameGroup, "\tTexture");
	addRadioButtonToGroup(wireFrameGroup, "\tWire");

	if((*wire))
		textures->disable();
	else
		textures->enable();

	addColumnToPanel(varPanel);

	GLUI_Listbox* texturesLand = addListboxToPanel(varPanel, "Landscape", landscapeSelect,8);

	texturesLand->add_item(1,"Mountains");
	texturesLand->add_item(2,"City");
	texturesLand->add_item(3,"Riverside");
	texturesLand->add_item(4,"City Night");


}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 5:
		{
			((LightingScene*) scene)->pauseResetClock();
			break;
		}
	
	}
}

