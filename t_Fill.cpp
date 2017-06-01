/************************************************************************************************

						t_Fill.cpp - Author: Tom Weaver - 4871898
							class Implementation of t_Fill.h

*************************************************************************************************/
#include "t_Fill.h"

t_Fill::t_Fill(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/fill.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Fill Canvas with Selected Colour | Ctrl+F";
	//Keyboard shortcut - leave blank if not required
	shortcut = "Ctrl+F";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "fill";
	//Any other initialisation operations go here
}


t_Fill::~t_Fill(void)
{
}


void t_Fill::use(Image_Data &data)
{
	//What must be done when the tool is used (user clicks on image)

	//This for loop iterates through the data held for the image and writes each pixel 
	//to the colour currently selected in the toolbox. 
	for (int i = 0 ; i < data.width ; i++)
	{
		for (int j = 0; j < data.height; j++)
		{
			data.setPixel(i, j);
		}
	}
}


void t_Fill::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
	
}