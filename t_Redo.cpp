#include "t_Redo.h"

t_Redo::t_Redo(void)
{
	icon = "./icons/redo.png";
	//On-hover tooltip
	tooltip = "Redo Tool";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "redo";
	//Any other initialisation operations go here
}


t_Redo::~t_Redo(void)
{
}


void t_Redo::use(Image_Data &data)
{
	//What must be done when the tool is used
}


void t_Redo::onPress(Image_Data &data)
{
	//Any other actions which must be done when the tool button is pressed go here
}