#include "t_Rectangle.h"

t_Rectangle::t_Rectangle(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/rectangle.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Rectangle Tool";
	//Keyboard shortcut - leave blank if not required
	shortcut = "";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "rectangle";
	//Any other initialisation operations go here
	waiting = false;
	released = false;
}


t_Rectangle::~t_Rectangle(void)
{
}


void t_Rectangle::use(Image_Data &data)
{
	//What must be done when the tool is used (user clicks on image)
	if(waiting)
	{
		if(!data.mouse_press)
		{
			if(data.cursor_x > -1 && data.cursor_x < data.width 
				&& data.cursor_y > -1 && data.cursor_y < data.height)
			{
				s_x = data.cursor_x;
				s_y = data.cursor_y;

				//Horizontal edges
				if(f_x < s_x)
				{
					for(int i = f_x; i < s_x; i++)
					{
						data.setPixel(i, f_y);
						data.setPixel(i, s_y);
					}
				}
				else
				{
					for(int i = s_x; i < f_x; i++)
					{
						data.setPixel(i, f_y);
						data.setPixel(i, s_y);
					}
				}

				//Vertical edges
				if(f_y < s_y)
				{
					for(int i = f_y; i < s_y; i++)
					{
						data.setPixel(f_x, i);
						data.setPixel(s_x, i);
					}
				}
				else
				{
					for(int i = s_y; i < f_y; i++)
					{
						data.setPixel(f_x, i);
						data.setPixel(s_x, i);
					}
				}
			}
			waiting = false;
		}
	}
	else
	{
		if(data.cursor_x > -1 && data.cursor_x < data.width 
			&& data.cursor_y > -1 && data.cursor_y < data.height
			&& !data.mouse_press)
		{
			f_x = data.cursor_x;
			f_y = data.cursor_y;
			waiting = true;
		}
	}
}


void t_Rectangle::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
}