#include "t_Example.h"

t_Example::t_Example(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/blank.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Add Tooltip Here";
	//Keyboard shortcut - leave blank if not required
	shortcut = "";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "CHANGEME";
	//Any other initialisation operations go here
}


t_Example::~t_Example(void)
{
}


void t_Example::use(Image_Data &data)
{
	//What must be done when the tool is used (user clicks on image)
}


void t_Example::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
}