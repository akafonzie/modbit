#include "t_Greyscale.h"

t_Greyscale::t_Greyscale(void)
{
	//Icon location
	icon = "./icons/gscale.png";
	//On-hover tooltip
	tooltip = "Convert to Greyscale";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "gScale";
	//Any other initialisation operations go here
}


t_Greyscale::~t_Greyscale(void)
{
}


void t_Greyscale::use(Image_Data &data)
{
	//What must be done when the tool is used

}


void t_Greyscale::onPress(Image_Data &data)
{
	//Any other actions which must be done when the tool button is pressed go here
	int greyValue;
	for(int y = 0; y < data.height; y++)
	{
		for(int x = 0; x < data.width; x++)
		{
			greyValue = (data.data[x][y].r + data.data[x][y].g + data.data[x][y].b)/3;
			data.data[x][y].r = greyValue;
			data.data[x][y].g = greyValue;
			data.data[x][y].b = greyValue;
			data.data[x][y].a = 255;
		}
	}
}