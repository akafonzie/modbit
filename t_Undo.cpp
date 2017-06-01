#include "t_Undo.h"

t_Undo::t_Undo(void)
{
	//Icon location
	icon = "./icons/undo.png";
	//On-hover tooltip
	tooltip = "Undo Tool";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "undo";
	//Any other initialisation operations go here
}


t_Undo::~t_Undo(void)
{
}


void t_Undo::use(Image_Data &data)
{
	//What must be done when the tool is used
	undoStack(data);
}

void t_Undo::undoStack(Image_Data &data)
{

}

void t_Undo::onPress(Image_Data &data)
{
	//Any other actions which must be done when the tool button is pressed go here
}