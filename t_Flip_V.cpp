#include "t_Flip_V.h"

t_Flip_V::t_Flip_V(void)
{
	//Icon location
	icon = "./icons/flip_v.png";
	//On-hover tooltip
	tooltip = "Flip Image Vertically";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "flip_v";
	//Any other initialisation operations go here
}


t_Flip_V::~t_Flip_V(void)
{
}


void t_Flip_V::use(Image_Data &data)
{
	//What must be done when the tool is used
}


void t_Flip_V::onPress(Image_Data &data)
{
	//Create a copy of the existing data
	Pixel** old_Image = new Pixel*[data.width];
	for(int i = 0; i < data.width; i++)
	{
		old_Image[i] = new Pixel[data.height];
	}

	//Form the new array reversing the vertical order
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

	//Cleanup the old image array
	for(int i=0; i < data.width; i++)
	{
       delete[] old_Image[i];
	}
	delete[] old_Image;
}