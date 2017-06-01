#include "t_Mirror.h"

t_Mirror::t_Mirror(void)
{
	//Icon location
	icon = "./icons/mirror.png";
	//On-hover tooltip
	tooltip = "Horizontally mirror the image";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "mirror_h";
	//Any other initialisation operations go here
}


t_Mirror::~t_Mirror(void)
{
}


void t_Mirror::use(Image_Data &data)
{
	//What must be done when the tool is used
}


void t_Mirror::onPress(Image_Data &data)
{
	//Create a copy of the existing data
	Pixel** old_Image = new Pixel*[data.width];
	for(int i = 0; i < data.width; i++)
	{
		old_Image[i] = new Pixel[data.height];
	}

	//Form the mirrored image
	for(int i=0; i < data.width; i++)
	{
		for(int j=0; j < data.height; j++)
		{
			//Until half way horizontally, continue as normal	
			if(i < data.width/2)
			{
				old_Image[i][j].r = data.data[i][j].r;
				old_Image[i][j].g = data.data[i][j].g;
				old_Image[i][j].b = data.data[i][j].b;
				old_Image[i][j].a = data.data[i][j].a;
			}
			//If past halfway horizontally, record the flipped image
			else
			{
			old_Image[i][j].r = data.data[data.width- 1 - i][j].r;
			old_Image[i][j].g = data.data[data.width- 1 - i][j].g;
			old_Image[i][j].b = data.data[data.width- 1 - i][j].b;
			old_Image[i][j].a = data.data[data.width- 1 - i][j].a;
			}
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