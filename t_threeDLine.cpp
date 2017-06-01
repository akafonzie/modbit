/************************************************************************************************

						t_threeDLine.cpp - Author: Tom Weaver - 4871898

		threeDLine.cpp is the implementation of the threeDLine.h class header file. 
		This tool draws a single line from the point of press to the edge of the canvas, 
		the direction of the line is changeable through 8 separate directions which are 
		initiated by consecutive presses of the toolbar button for this tool. 

*************************************************************************************************/


#include "t_threeDLine.h"

t_threeDLine::t_threeDLine(void)
{
	//Icon location
	icon = "./icons/linegradient.png";
	//On-hover tooltip
	tooltip = "Gradient Line Tool | Press Button Repeatedly to Adjust the Direction (Clockwise)";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "threedline";
	//Any other initialisation operations go here
	dir = 0;
}


t_threeDLine::~t_threeDLine(void)
{
}


void t_threeDLine::use(Image_Data &data)
{
	//What must be done when the tool is used

	//Firstly, grab the current coordinates of the cursor and store them
	//in two ints to ascertain where the drawing should begin from. 
	int cPx = data.cursor_x;
	int cPy = data.cursor_y;
	//call the draw method with the cursor coordinates and also pass it a reference to 
	//the Image_Data data object so it can call the methods within Image_Data to draw to the array.
	draw(data, cPx, cPy);
}

void t_threeDLine::draw(Image_Data &data, int x, int y)
{
	//The draw method uses a switch case statement to cycle through the different directions 
	//available to draw to which is updated via the press of the tool button, ie each time the 
	//button is pressed the direction cycles through 8 possible iterations in a clockwise cycle. 
	//The method makes use of the Global colour so all lines will be drawn in the users chosen colour, 
	//selectable from the colour toolbox. 
	switch (dir)
	{
	case 1:
		//Direction 1 is to begin drawing from the top-left corner of the canvas.
		while (x > 0 && y > 0)
		{
			data.setPixel(x, y);
			x--;y--;
		}
		break;
	case 2:
		//Direction 2 is to begin drawing from the top of the canvas at the x position. 
		while (x > 0 && (y< data.height && y>0) )
		{
			data.setPixel(x,y);
			y--;
		}
		break;
	case 3:
		//Direction 3 is to begin drawing from the top-right corner of the canvas.
		while (x<data.width && y > 0)
		{
			data.setPixel(x, y);
			x++;y--;
		}
		break;
	case 4:
		//Direction 4 is to begin drawing from the right side of the canvas at the y position. 
		while (y > 0 && (x< data.width && x>0) )
		{
			data.setPixel(x,y);
			x++;
		}
		break;
	case 5: 
		//Direction 5 is to begin drawing from the bottom-right corner of the canvas. 
		while (x < data.width && y<data.height)
		{
			data.setPixel(x, y);
			x++;y++;
		}
		break;
	case 6: 
		//Direction 6 is to begin drawing from the bottom of the canvas at the y position.
		while (x > 0 && (y< data.height && y>0) )
		{
			data.setPixel(x,y);
			y++;
		}
		break;
	case 7: 
		//Direction 7 is to begin drawing from the bottom-right corner of the canvas
		while (x>0&&y<data.height)
		{
			data.setPixel(x,y);
			x--;y++;
		}
		break;
	case 8:
		//Direction 8 is to begin drawing from the left side of the canvas at the y position
		while (y > 0 && (x< data.width && x>0) )
		{
			data.setPixel(x,y);
			x--;
		}
		break;
	default:
		break;

	}
	//A small if statement to ensure that the number of directions can never be less than one
	//or greater than 8, so it cycles through all 8 directinons and then starts again from the 
	//first direction. 
	if (dir < 1 || dir > 8){dir=1;}
}



void t_threeDLine::onPress(Image_Data &data)
{
	//On each press of the tool's button in the toolbar the direction variable will be 
	//increased by one so the draw method can effectively update the chosen direction.
	dir+=1;
	//Any other actions which must be done when the tool button is pressed go here
}
