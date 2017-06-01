#include "t_Rotate.h"

t_Rotate::t_Rotate(void)
{
	//Icon location
	icon = "./icons/rotate.png";
	//On-hover tooltip
	tooltip = "Rotate the image";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "rotate";
	//Any other initialisation operations go here
}


t_Rotate::~t_Rotate(void)
{
}


void t_Rotate::use(Image_Data &data)
{
	//What must be done when the tool is used
}


void t_Rotate::onPress(Image_Data &data)
{
	int width = data.width;
	int height = data.height;

	//Create a copy of the existing data
	Pixel** old_Image = new Pixel*[data.width];
	for(int i = 0; i < data.width; i++)
	{
		old_Image[i] = new Pixel[data.height];
	}

	for(int i=0; i < data.width; i++)
	{
		for(int j=0; j < data.height; j++)
		{
			old_Image[i][j].r = data.data[i][data.height - 1 - j].r;
			old_Image[i][j].g = data.data[i][data.height - 1 - j].g;
			old_Image[i][j].b = data.data[i][data.height - 1 - j].b;
			old_Image[i][j].a = data.data[i][data.height - 1 - j].a;
		}
	}

	data.setDimensions(height, width);

	for(int i = 0; i < data.width; i++)
	{
		for(int j = 0; j < data.height; j++)
		{
			 data.data[i][j].r = old_Image[j][i].r;
			 data.data[i][j].g = old_Image[j][i].g;
			 data.data[i][j].b = old_Image[j][i].b;
			 data.data[i][j].a = old_Image[j][i].a;
		}
	}

	//Cleanup the old image array
	for(int i=0; i < data.width; i++)
	{
       delete[] old_Image[i];
	}
	delete[] old_Image;
}