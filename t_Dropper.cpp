/************************************************************************************************

						t_Dropper.cpp - Author: Tom Weaver - 4871898
							class Implementation of t_Dropper.h

*************************************************************************************************/
#include "t_Dropper.h"

t_Dropper::t_Dropper(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/dropper.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Copy Selected Colour";
	//Keyboard shortcut - leave blank if not required
	shortcut = "";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "dropper";
	//Any other initialisation operations go here
}


t_Dropper::~t_Dropper(void)
{
}

/*
The use() method of t_Dropper sets a boolean variable "dropper" held within the Image_Data class 
to true, all further computation is completed in the Main_Window.cpp: 

void MAIN_WINDOW::colourPicker()
{
	if (data.dropper)
	{
		if(data.cursor_x > -1 && data.cursor_x < data.width
			&& data.cursor_y > -1 && data.cursor_y < data.height)
			{
				Pixel temp;
				int x = data.cursor_x;
				int y = data.cursor_y;
				temp = data.getPixel(x, y);
				QString tamp = QString("%1-%2-%3").arg(temp.r).arg(temp.g).arg(temp.b);
				theToolBox.setColour(tamp);
				data.colour.r = temp.r;
				data.colour.g = temp.g;
				data.colour.b = temp.b;
				data.colour.a = temp.a;
				data.dropper=false;
			}
	}
}

*/
void t_Dropper::use(Image_Data &data)
{
	//What must be done when the tool is used (user clicks on image)
	data.dropper = true;
}


void t_Dropper::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
}