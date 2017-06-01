#include "t_Pencil.h"

t_Pencil::t_Pencil(void)
{
	//Icon location
	icon = "./icons/pencil.png";
	//On-hover tooltip
	tooltip = "Pencil Tool";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "pencil";
}


t_Pencil::~t_Pencil(void)
{
}

void t_Pencil::use(Image_Data &data)
{
	paint(data);
}

void t_Pencil::onPress(Image_Data &data)
{
	//Any other actions which must be done when the tool button is pressed go here
}

void t_Pencil::paint(Image_Data &data)
{
	//Error checking
	if(data.cursor_x > -1 && data.cursor_x < data.width 
		&& data.cursor_y > -1 && data.cursor_y < data.height)
	{
		data.setPixel(data.cursor_x, data.cursor_y);
	}

	if(data.mouse_drag)
	{
		data.vec1 = QVector2D(data.prevcursor_x, data.prevcursor_y);
		data.vec2 = QVector2D(data.cursor_x, data.cursor_y);
		if ( ( (data.vec1.x() > 0) && (data.vec2.x() > 0) ) &&
			 ( (data.vec1.y() > 0) && (data.vec2.y() > 0) ) &&
			 ( (data.vec1.x() < data.width)&&(data.vec2.x() < data.width) ) &&
			 ( (data.vec1.y() < data.height)&&(data.vec2.y() < data.height))
		   ) 
		{
			data.interp=true;
		}
	}
	if(data.interp)
	{

		int vec1x = data.vec1.x();
		int vec1y = data.vec1.y();
		int vec2x = data.vec2.x();
		int vec2y = data.vec2.y();
		if (vec1x > vec2x){data.intPoint = vec1x - vec2x;}
		for (float i = 0.0; i <= 1.0; i+=0.01)
		{
			float ang = (  ( 1-cos(i*M_PI) )/2  );
			int point_x =  vec1x * (1-ang) + vec2x * ang;
			int point_y = vec1y *(1-ang)+ vec2y*ang;
			data.intVec.push_back(QVector2D(point_x, point_y));
		}
	}
	if(data.cursor_x > -1 && data.cursor_x < data.width 
		&& data.cursor_y > -1 && data.cursor_y < data.height)
	{
		for (int v = 0 ; v <data.intVec.size(); v++)
		{
			int xpos = data.intVec[v].x();
			int ypos = data.intVec[v].y();
			data.setPixel(xpos, ypos);
		}
	}
	data.intVec.clear();
	data.interp=false;
}