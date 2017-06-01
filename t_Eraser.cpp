/************************************************************************************************

						t_Eraser.cpp - Author: Tom Weaver - 4871898
							class Implementation of t_Eraser.h

*************************************************************************************************/
#include "t_Eraser.h"

t_Eraser::t_Eraser(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/eraser.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Eraser (erases to white) | Ctrl+E";
	//Keyboard shortcut - leave blank if not required
	shortcut = "Ctrl+E";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "eraser";
	//Any other initialisation operations go here
}


t_Eraser::~t_Eraser(void)
{
}


void t_Eraser::use(Image_Data &data)
{
	//What must be done when the tool is used (user clicks on image)
	
	//Similarly to the brush tool (t_Brush) implemented by Adam, the nested for loops 
	//iterate through the size variable and set the pixels in the Image_Data object
	for(int i = -floor(size/2); i < ceil(size/2); i++)
	{
		for(int j = -floor(size/2); j < ceil(size/2); j++)
		{
			//Error checking
			if(data.cursor_x+i > -1 && data.cursor_x+i < data.width 
				&& data.cursor_y+j > -1 && data.cursor_y+j < data.height)
			{
				data.setPixel(data.cursor_x+i, data.cursor_y+j, 255, 255, 255);
			}
		}
	}

}


void t_Eraser::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
}

//This method allows the Eraser to be resized by the tool size Slider in the main window toolbar. 
void t_Eraser::setSize(int sz)
{
	size = sz;
}