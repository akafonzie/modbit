#include "t_Resize.h"

t_Resize::t_Resize(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/resize.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Resize the image";
	//Keyboard shortcut - leave blank if not required
	shortcut = "";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "resize";
	//Any other initialisation operations go here
}


t_Resize::~t_Resize(void)
{
}


void t_Resize::use(Image_Data &data)
{
	//What must be done when the tool is used (user clicks on image)

}


void t_Resize::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
	resize("1024/768", data);
}

void t_Resize::resize(QString xy, Image_Data &data)
{
	//For now I will hard code a resolution change as proof of concept, however
	//this should be modified to take a QString value from a popup dialogue box
	//similar to the current colour toolbox!

	//Declare a QStringList
	QStringList xylist;
	//Split the input string at the / symbol
	xylist = xy.split("/");
	//Save these changes as the new resolution
	int new_Width = xylist[0].toInt();
	int new_Height = xylist[1].toInt();
	int old_Height = data.height;
	int old_Width = data.width;

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
			old_Image[i][j].r = data.data[i][j].r;
			old_Image[i][j].g = data.data[i][j].g;
			old_Image[i][j].b = data.data[i][j].b;
			old_Image[i][j].a = data.data[i][j].a;
		}
	}

	//Resize the image
	data.setDimensions(new_Width, new_Height);

	//Loop through the new image
	for(int i = 0; i < new_Width; i++)
	{
		for(int j = 0; j < new_Height; j++)
		{
			//If it is within the scope of the original image, set it as that colour
			if(i < old_Width && j < old_Height)
			{
				 data.data[i][j].r = old_Image[i][j].r;
				 data.data[i][j].g = old_Image[i][j].g;
				 data.data[i][j].b = old_Image[i][j].b;
				 data.data[i][j].a = old_Image[i][j].a;
			}
			//Else set the colour to white
			else
			{
				data.data[i][j].r = 255;
				data.data[i][j].g = 255;
				data.data[i][j].b = 255;
				data.data[i][j].a = 255;
			}
		}
	}

	//Cleanup the temporary array
	for(int i=0; i < old_Width; i++)
	{
       delete[] old_Image[i];
	}
	delete[] old_Image;
}