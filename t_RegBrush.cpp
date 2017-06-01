#include "t_RegBrush.h"

t_RegBrush::t_RegBrush(void)
{
	//Icon location - the file location of the tool icon
	icon = "./icons/regbrush2.png";
	//On-hover tooltip - what will be displayed when the user hovers over the button
	tooltip = "Soft Brush Tool";
	//Keyboard shortcut - leave blank if not required
	shortcut = "";
	//Set the tool id - THIS MUST BE UNIQUE
	id = "regbrush";
	//Any other initialisation operations go here
	brushsize=5;

}


t_RegBrush::~t_RegBrush(void)
{
}


void t_RegBrush::use(Image_Data &data)
{
	paint(data);
	//What must be done when the tool is used (user clicks on image)
}


void t_RegBrush::onPress(Image_Data &data)
{
	//Anything which must be done when the tool button is pressed should go here
}

void t_RegBrush::paint(Image_Data &data){
	//Brush size test
	//Algorithm to place a square brush the specified size
	//
	// |*********|
	// |		 |         
	// |    c    |
	// |         |
	// |_________|

	brushsize = size+20;
	if(brushsize%2==0){ //if even number
		brushsize+=1;
	}
	

	genKernel(brushsize);

	for(int i = -floor(brushsize/2); i < ceil(brushsize/2); i++)
	{ 
		for(int j = -floor(brushsize/2); j < ceil(brushsize/2); j++)
		{
			//Error checking
			if(data.cursor_x+i > -1 && data.cursor_x+i < data.width 
				&& data.cursor_y+j > -1 && data.cursor_y+j < data.height)
			{					
				setPixelColour(data, data.cursor_x+i, data.cursor_y+j, i+floor(brushsize/2), j+floor(brushsize/2));
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

		for(int i = -floor(brushsize/2); i < ceil(brushsize/2); i++)
		{
			for(int j = -floor(brushsize/2); j < ceil(brushsize/2); j++)
			{
				if(data.cursor_x+i > -1 && data.cursor_x+i < data.width 
				&& data.cursor_y+j > -1 && data.cursor_y+j < data.height)
				{
					for (int v = 0 ; v <data.intVec.size(); v++)
					{
						int xpos = data.intVec[v].x();
						int ypos = data.intVec[v].y();
						
						if(xpos+i > -1 && xpos+i < data.width 
							&& ypos+j > -1 && ypos+j < data.height){
							setPixelColour(data,xpos+i,ypos+j, i+floor(brushsize/2), j+floor(brushsize/2) );
						}
						
					}
				}
			}
		}

	data.intVec.clear();
	data.interp=false;
	

}


void t_RegBrush::setBrushSize(int sz)
{
	size = sz;
	//newsize = sz;
}



void t_RegBrush::setPixelColour(Image_Data &data, int xp, int yp, int kernx, int kerny){
	//index is the corresponding kernel position
	opacity = kernel[kernx][kerny];

	int avgr = floor(data.data[xp][yp].r * (1-opacity) + data.colour.r*opacity);
	int avgg = floor(data.data[xp][yp].g * (1-opacity) + data.colour.g*opacity);
	int avgb = floor(data.data[xp][yp].b * (1-opacity) + data.colour.b*opacity);

	data.setPixel(xp, yp, avgr, avgg, avgb);
	
}


void t_RegBrush::genKernel(int fsize){

	//g(u,v) = exp -( ((u-u0)^2 + (v-v0)^2) / (2*(sigma^2)) )  -> formula for gaussian

	//trial and error sigma val, this distributes the kernel so it looks circular,
	//minimum val at about fsize/15
	float sigma = fsize/15; 
	int middle = (fsize+1)/2;
	float sig1 = 2*(pow(sigma,2));	
	float total=0;
	float **v = new float*[fsize];
	float **u = new float*[fsize];
	
	//create array with vals repeating from 1 to fsize
	//the 2d array would look like this for fsize=3:
	//
	// 1 2 3
	// 1 2 3
	// 1 2 3
	//create array with vals repeating from 1 to fsize
	//the 2d array for fsize = 3 would be:
	//
	// 1 1 1
	// 2 2 2
	// 3 3 3

	for(int i = 0; i < fsize; i++)
	{
		v[i] = new float[fsize];
		u[i] = new float[fsize];
	}

	for(int i=0; i<fsize; i++){
		for(int j=0; j<fsize; j++){
			int tempv = i+1;
			v[i][j] = pow( (tempv-middle), 2); //(v-v0)^2)
			int tempu = j+1;
			u[i][j] = pow( (tempu-middle), 2); //(u-u0)^2)
		}
	}

	kernel = new float*[fsize]; //this will contain the coeffs
	for(int i = 0; i < fsize; i++)
	{
		kernel[i] = new float[fsize];	
	}

	for(int i=0; i<fsize; i++){
		for(int j=0; j<fsize; j++){
			float temp = (u[i][j]+v[i][j])/sig1; // divide by(2*(sigma^2))
			kernel[i][j] = exp(temp*(-1)); //exp(-kernel)	
		}
	}

	for(int i = 0; i < fsize; i++) {
		delete [] u[i];
		delete [] v[i];
	}
	
	delete[] u;
	delete[] v;
}

