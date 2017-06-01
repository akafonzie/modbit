//***************************************************************//
// This tool uses Bresenham's Line drawing algorithm, as         //
// shown here:                                                   //
// http://www.cs.toronto.edu/~smalik/418/tutorial2_bresenham.pdf //
//***************************************************************//

#include "t_Line.h"

t_Line::t_Line(void)
{
	//Icon location
	icon = "./icons/linetool2.png";
	//On-hover tooltip
	tooltip = "Line Tool";
	//Keyboard shortcut
	shortcut = "CTRL+l";
	//Set the tool id
	id = "line";
	justClicked=true;
	start_x = 0;
	start_y = 0;
	end_x = 0;
	end_y = 0;
}


t_Line::~t_Line(void)
{
}

void t_Line::use(Image_Data &data)
{
	draw(data);
	
}

void t_Line::onPress(Image_Data &data)
{
	
	//Any other actions which must be done when the tool button is pressed go here
}

void t_Line::draw(Image_Data &data)
{
	//only set these when the mouse is first pressed
	if(justClicked){
		start_x = data.cursor_x;
		start_y = data.cursor_y;
		justClicked=false;
	}


			
	
	if(!data.mouse_press){ //if the mouse has been released, draw the pixels
			end_x = data.cursor_x;
			end_y = data.cursor_y;
			calcLinePoints(start_x, start_y, end_x, end_y);

			for (int v = 0 ; v <linePoints.size(); v++) //the line points represent all the cursor points
			{
				for(int i = -floor(size/2); i < ceil(size/2); i++) //also loop through the brush area to set 
																	   //pixels surrounding the line points
				{
					for(int j = -floor(size/2); j < ceil(size/2); j++)
					{
						//Error checking
						if(linePoints[v].x()+i > -1 && linePoints[v].x()+i < data.width 
							&& linePoints[v].y()+j > -1 && linePoints[v].y()+j < data.height)
						{				
									data.setPixel(linePoints[v].x()+i, linePoints[v].y()+j);
							
						}
					}
				}
			}
			linePoints.clear();
			justClicked =true;
	}
	

	
}

void t_Line::setBrushSize(int sz)
{
	size = sz;
}


void t_Line::calcLinePoints(int x1, int y1, int x2, int y2){
	
	 int inc; 
	 int dx, dy, dxabs, dyabs;
	 int d, two_dy, two_dxdy; 
	 int y;

	 dx = (x2 - x1); 
	 dy = (y2 - y1); 
	 dxabs = abs(dx); dyabs = abs(dy); 
 
	 //Swap end points if x1 > x2, so you always draw bottom left to top right, or top left to bottom right
	 if (x1 > x2) 
	 { 
		 calcLinePoints(x2, y2, x1, y1);
		 return;
	 } 
 	
	 if(dyabs > dxabs){ //increases in y faster than x
		
		 calcLinePointsSteep(x1,y1,x2,y2);
		 return;
	 }

	 linePoints.push_back(QVector2D(x1, y1)); //add first point
 
	 if( (dyabs==1 && dxabs==1) || //the line is only 1 or 2 pixels long
		 (dyabs==1 && dxabs==0) ||
		 (dyabs==0 && dxabs==1) ||
		 (dyabs==0 && dxabs==0)){
		linePoints.push_back(QVector2D(x2, y2)); //only add the last point
	}

	 else{
			 //Line goes down so decrement y values
			 if (dy < 0) 
			 { 
				 inc = -1; 
				 dy = -dy;
			 } 
			 else if (dy > 0)
			 { 
				inc = 1; 
			 } 
			 else{
				inc = 0; //horizontal
			 }
 
			 // Bresenham bits 
			 two_dy = 2 * dy; //difference in two midpoints if you select E pixel
			 two_dxdy = 2 * dy - 2 * dx; //difference in two midpoints if you select NE pixel
			 d = 2 * dy - dx;  //the midpoint between 2 pixels at a point on the line
			 y = y1 + inc; 
			 
			  if(dx==0){ //vertical
				  if(dy < 0){
					  for( int j = y; j > y2; j--){
						  linePoints.push_back(QVector2D(x1,y));
					  }
				  }
				  else{
					  for( int j = y; j < y2; j++){
						  linePoints.push_back(QVector2D(x1,y));
					  }

				  }
			  }

				  else{ //not vertical
					 for (int x = x1+1; x < x2; x++) 
					 { 
          
						linePoints.push_back(QVector2D(x, y));
						if (d <= 0) //above the midpoint, select E pixel
						{ 
							d += two_dy; //calc next midpoint
						} 
						else //below the midpoint, select NE pixel
						{ 
							d += two_dxdy; //calc next midpoint
							y += inc; //increase or decrease y depending on direction of line
						}

					 
					 }

					
				  }

				  linePoints.push_back(QVector2D(x2,y2));
	}

}



void t_Line::calcLinePointsSteep(int x1, int y1, int x2, int y2){
	 
	 int inc; //always increasing x
	 int dx, dy, dxabs, dyabs;
	 int d, two_dx, two_dxdy; 
	 int x;
	

	 dx = (x2 - x1); 
	 dy = (y2 - y1); 
	 dxabs = abs(dx); dyabs = abs(dy); 

	  if (y1 > y2) 
	 { 
		 calcLinePointsSteep(x2, y2, x1, y1);
		 return;
	 } 
 	
	 linePoints.push_back(QVector2D(x1, y1)); //add first point
 
	 if( (dyabs==1 && dxabs==1) ||
		 (dyabs==1 && dxabs==0) ||
		 (dyabs==0 && dxabs==1) ||
		 (dyabs==0 && dxabs==0)){
		linePoints.push_back(QVector2D(x2, y2)); //only add the last point
	}

	 else{
			 if (dx < 0) 
			 { 
				 inc = -1; 
				 dx = -dx;
			 } 
			 else if (dx > 0)
			 { 
				inc = 1; 
			 } 
			 else{
				inc = 0; //horizontal
			 }

			 // Bresenham bits 
			 two_dx = 2 * dx; //difference in two midpoints if you select N pixel
			 two_dxdy = 2 * dx - 2 * dy; //difference in two midpoints if you select NE pixel
			 d = 2 * dx - dy;  //the midpoint between 2 pixels at a point on the line
			 x = x1 + inc; 

		
					 for (int y = y1+1; y < y2; y++) 
					 { 
			            
						linePoints.push_back(QVector2D(x, y));

						if (d <= 0) //line is above the midpoint, select N pixel, x stays the same
						{ 
							d += two_dx; //calc next midpoint
						} 
						else //line is below the midpoint, select NE pixel, x and y change 
						{ 
							d += two_dxdy; //calc next midpoint
							x += inc;
						}

							  
					}

			 linePoints.push_back(QVector2D(x2, y2));
	 }

}