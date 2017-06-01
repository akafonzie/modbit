#include "t_Blur.h"

t_Blur::t_Blur(void)
{
	//Icon location
	icon = "./icons/blur2.png";
	//On-hover tooltip
	tooltip = "Blur tool";
	//Keyboard shortcut
	shortcut = "";
	//Set the tool id
	id = "blur";
	//Any other initialisation operations go here
}


t_Blur::~t_Blur(void)
{
}


void t_Blur::use(Image_Data &data)
{
	blurPixels(data);
}


void t_Blur::onPress(Image_Data &data)
{
	//Any other actions which must be done when the tool button is pressed go here
	
}

void t_Blur::blurPixels(Image_Data &image){
	
	int brushlength = ceil(size/2) - (-floor(size/2));
	float *temp_rgb_vals = new float[brushlength*brushlength*3];

	getBlurVals(temp_rgb_vals, image); //store blurred values in section the size of the brush in an array
	setBlurVals(temp_rgb_vals, image); //use values in array to update the image data values
}

void t_Blur::getBlurVals(float temp_rgb_vals[], Image_Data &image){

	int kernelsize = 25;
	float kernelval = 1.0f/kernelsize; //find the sum of the data values*kernelval to get avg of pixels
	//to use different filters, could use an array of size kernelsize and apply to each iteration
	int bordersize = (sqrt(kernelsize)-1)/2; //used to get the right sized section from data
	
	int counter=0; //index for temp_rgb_vals

	for(int i = -floor(size/2); i < ceil(size/2); i++) //loop through brush area
	{
		for(int j = -floor(size/2); j < ceil(size/2); j++) //loop through brush area
		{
			//Error checking
			if(image.cursor_x+i > -1 && image.cursor_x+i < image.width 
				&& image.cursor_y+j > -1 && image.cursor_y+j < image.height)
			{
				int currentx = image.cursor_x+i; int currenty = image.cursor_y+j;
				int min_x = currentx-bordersize; int max_x = currentx+bordersize; //get the boundaries for the
				int min_y = currenty-bordersize; int max_y = currenty+bordersize; //section of data to blur

				float interp_val_r, interp_val_g, interp_val_b;
				float sum_r = 0; float sum_g = 0; float sum_b=0;

				for (int x = min_x; x < (max_x+1); x++){ //loop through width of kernel sized section of data
					for (int y = min_y; y < (max_y+1); y++){ //loop through height
						if( x<0 || x>image.width-1 || y<0 || y>image.height-1){ //trying to access out of bounds
							interp_val_b = 255 * kernelval;
							interp_val_g = 255 * kernelval;
							interp_val_b = 255 * kernelval;
						}
						else{
							interp_val_r = image.data[x][y].r * kernelval; //apply blur kernel
							interp_val_g = image.data[x][y].g * kernelval;
							interp_val_b = image.data[x][y].b * kernelval;
						}
						sum_r+=interp_val_r;
						sum_g+=interp_val_g;
						sum_b+=interp_val_b;
					}
				}

				//can't change actual data yet as the new vals would be used in the loop,
				//need to hold them teporarily then change when the loop is finished
				temp_rgb_vals[counter] = sum_r;
				counter++;
				temp_rgb_vals[counter] = sum_g;
				counter++;
				temp_rgb_vals[counter] = sum_b;
				counter++;				
			}
		}
		
	}
}


void t_Blur::setBlurVals(float temp_rgb_vals[], Image_Data &image){
	int counter=0;

	for(int k = -floor(size/2); k < ceil(size/2); k++) //loop through brush area
	{
		for(int l = -floor(size/2); l < ceil(size/2); l++) //loop through brush area
		{
			//Error checking
			if(image.cursor_x+k > -1 && image.cursor_x+k < image.width 
				&& image.cursor_y+l > -1 && image.cursor_y+l < image.height)
			{
				int r = floor(temp_rgb_vals[counter]); //convert back into an int, as rgb can only be int
				counter++;
				int g = floor(temp_rgb_vals[counter]);
				counter++;
				int b = floor(temp_rgb_vals[counter]);
				counter++;
				image.setPixel(image.cursor_x+k, image.cursor_y+l, r,g,b);
			}
		}
	}
}

void t_Blur::setBrushSize(int sz)
{
	size = sz;
}