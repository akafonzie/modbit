#include "t_Flip_H.h"

t_Flip_H::t_Flip_H(void)
{
	//Icon location
	icon = "./icons/flip_h.png";
	//On-hover tooltip
	tooltip = "Flip Image Horizontally";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "flip_h";
	//Any other initialisation operations go here
}


t_Flip_H::~t_Flip_H(void)
{
}


void t_Flip_H::use(Image_Data &data)
{
	//What must be done when the tool is used
}


void t_Flip_H::onPress(Image_Data &data)
{
	//Create a copy of the existing data
	Pixel** old_Image = new Pixel*[data.width];
	for(int i = 0; i < data.width; i++)
	{
		old_Image[i] = new Pixel[data.height];
	}

	//Form the new array reversing the horizontal order
	for(int i=0; i < data.width; i++)
	{
		for(int j=0; j < data.height; j++)
		{
			old_Image[i][j].r = data.data[data.width- 1 - i][j].r;
			old_Image[i][j].g = data.data[data.width- 1 - i][j].g;
			old_Image[i][j].b = data.data[data.width- 1 - i][j].b;
			old_Image[i][j].a = data.data[data.width- 1 - i][j].a;
		}
	}

	//Save the new data to the active image_data array
	for(int i = 0; i < data.width; i++)
	{
		for(int j = 0; j < data.height; j++)
		{
			 data.data[i][j].r = old_Image[i][j].r;
			 data.data[i][j].g = old_Image[i][j].g;
			 data.data[i][j].b = old_Image[i][j].b;
			 data.data[i][j].a = old_Image[i][j].a;
		}
	}

	//Cleanup the obsolete array
	for(int i=0; i < data.width; i++)
	{
       delete[] old_Image[i];
	}
	delete[] old_Image;
}