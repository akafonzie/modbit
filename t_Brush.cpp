/************************************************************************************************

Interpolation methods interpreted from this site: http://paulbourke.net/miscellaneous/interpolation/

*************************************************************************************************/

#include "t_Brush.h"

t_Brush::t_Brush(void)
{
	//Icon location
	icon = "./icons/brush.png";
	//On-hover tooltip
	tooltip = "Paintbrush Tool";
	//Keyboard shortcut
	shortcut = "CTRL+b";
	//Set the tool id
	id = "brush";
}


t_Brush::~t_Brush(void)
{
}

void t_Brush::use(Image_Data &data)
{
	paint(data);
}

void t_Brush::onPress(Image_Data &data)
{
	//Any other actions which must be done when the tool button is pressed go here
}

void t_Brush::paint(Image_Data &data)
{
	//Brush size test
	//Algorithm to place a square brush the specified size
	for(int i = -floor(size/2); i < ceil(size/2); i++)
	{
		/*xs is used when calculating the distance between the current point 
			and the centre of the brush*/
		int xs = ((data.cursor_x-data.cursor_x+i)*(data.cursor_x-data.cursor_x+i));
		for(int j = -floor(size/2); j < ceil(size/2); j++)
		{
			/*ys is used when calculating the distance between the current point 
				and the centre of the brush*/
			int ys = ((data.cursor_y-data.cursor_y+j)*(data.cursor_y-data.cursor_y+j));
			//Error checking
			if(data.cursor_x+i > -1 && data.cursor_x+i < data.width 
				&& data.cursor_y+j > -1 && data.cursor_y+j < data.height
				/*sqrt(xs + ys) is the distance between the centre of the brush (cursor position)
					and the current point in the canvas square containing the circle. If this is
					larger than half the intended brush size (so the radius of the circle)
					the point does not need to be rendered as it is outside the bounds of the brush.
					The closer the value is to the value 'size/2', the closer the point is to the 
					edge of	the circle*/
				&& sqrt(xs + ys) < size/2)
			{
				data.setPixel(data.cursor_x+i, data.cursor_y+j);
			}
		}
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
		for(int i = -floor(size/2); i < ceil(size/2); i++)
		{
			for(int j = -floor(size/2); j < ceil(size/2); j++)
			{
				if(data.cursor_x+i > -1 && data.cursor_x+i < data.width 
				&& data.cursor_y+j > -1 && data.cursor_y+j < data.height)
				{
					for (int v = 0 ; v <data.intVec.size(); v++)
					{
						int xpos = data.intVec[v].x();
						int ypos = data.intVec[v].y();
						if(xpos+i > -1 && xpos+i < data.width 
							&& ypos+j > -1 && ypos+j < data.height
							&& sqrt(((data.cursor_x-data.cursor_x+i)*(data.cursor_x-data.cursor_x+i))
								+((data.cursor_y-data.cursor_y+j)*(data.cursor_y-data.cursor_y+j)))
								< size/2)
						{
							data.setPixel(xpos+i,ypos+j);
						}
					}
				}
			}
		}
		data.intVec.clear();
	data.interp=false;

}

void t_Brush::setBrushSize(int sz)
{
	size = sz;
}