#include "Image_Data.h"



Image_Data::Image_Data(void)
{
	//Read in image here
	width = 512;
	height = 512;
	
	//Set the initial selected colour to white (I think you mean red ;) /tom)
	colour.r = 255;
	colour.g = 0;
	colour.b = 0;
	colour.a = 255;

	mouse_press = mouse_release = dropper = false;

	//Set the data size to match the loaded image size
	data = new Pixel*[width];
	for(int i = 0; i < width; i++)
	{
		data[i] = new Pixel[height];
	}	
}




Image_Data::~Image_Data(void)
{

}




void Image_Data::fillArray(){

	//Initialise an ordinary white pixel
	Pixel image_colour;
	//Red
	image_colour.r = 255;
	//Green
	image_colour.g = 255;
	//Blue
	image_colour.b = 255;
	//Alpha
	image_colour.a = 255;

	/*Sets all pixels to the colour (I changed this to blue), I also swapped height and width round
		which now appears to be the correct orientation*/
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			data[x][y].r = image_colour.r;
			data[x][y].g = image_colour.g;
			data[x][y].b = image_colour.b;
			data[x][y].a = image_colour.a;

		}
	}
}




void Image_Data::fillArrayFromImage(uint8_t* pixels){


		//pixels is a 1d array, need to copy into 2d array

		int pixels_counter=0; //iterator for the pixels array

		for(int j=this->height-1; j>-1; j--){ //row, goes backwards otherwise image is upside down
			for(int i=0; i<this->width; i++){ //column
				//1917
				

				data[i][j].r=pixels[pixels_counter]; //counter is at first of group of 3 (0,3,6,9 etc)

				pixels_counter++; //counter is at second of group of 3 (1,4,7,10 etc)
				data[i][j].g=pixels[pixels_counter]; 

				pixels_counter++; //counter is at third of group of 3 (2,5,8,11 etc)
				data[i][j].b=pixels[pixels_counter];
				
				data[i][j].a=255; //bmp does not have alpha value so set to 25

				pixels_counter++; //counter is at next start of group of 3 (3,6,9,12 etc)			
				
			}

		}

}


void Image_Data::setDimensions(int new_width, int new_height)
{
	for(int i=0; i < width; i++)
	{
       delete[] data[i];
	}
	delete[] data;


	width = new_width;
	height = new_height;
	
	//Re-initialise the pixel array
	data = new Pixel*[width];
	for(int i = 0; i < width; i++)
	{
		data[i] = new Pixel[height];
	}
}




void Image_Data::setPixel(int x, int y)
{
	//Add the pixel to the correct position in the data array
	data[x][y] = colour;
}

void Image_Data::setPixel(int x, int y, int pr, int pg, int pb)
{
	//Add the pixel to the correct position in the data array
	data[x][y].r = pr;
	data[x][y].g = pg;
	data[x][y].b = pb;

}

Pixel Image_Data::getPixel(int x, int y)
{
	Pixel temp;
	temp.r = data[x][y].r;
	temp.g = data[x][y].g;
	temp.b = data[x][y].b;
	temp.a = data[x][y].a;
	return temp;
}



uint8_t* Image_Data::arrayToBMP(){

	//data is a 2d array, need to copy into 1d array
	
	//need to check both dimensions as bitmaps can only be stored in 
	//bytes of multiples of 4, if they aren't then pad them
	int wremainder=this->width%4;
	int hremainder=this->height%4;

	if (!(wremainder==0)&&(hremainder==0)){ //if only width needs padding
		int padw = 4-wremainder;
		int padh=0;
		padArray(padw,padh);
	}
	else if(wremainder==0 && !(hremainder==0)){ //if only height needs padding
		int padw=0;
		int padh=4-hremainder;
		padArray(padw,padh);
	}
	else if(!(wremainder==0)&& !(hremainder==0)){ //if both need padding
		int padw=4-wremainder;
		int padh=4-hremainder;
		padArray(padw,padh);
	}
	
	int pixels_size=this->width*this->height*3;
	uint8_t* BMParray = new uint8_t[pixels_size];

	int heightcounter=this->height-1; //start at end otherwise bmp is upside down!
	int widthcounter=0;

	for(int i=0; i<pixels_size; i++){
		BMParray[i] = this->data[widthcounter][heightcounter].r;
		i++;
		BMParray[i] = this->data[widthcounter][heightcounter].g;
		i++;
		BMParray[i] = this->data[widthcounter][heightcounter].b;
		widthcounter++;

		if(widthcounter==this->width){ //if end of row
			widthcounter=0; //start from beginning of row
			heightcounter--; //go up to next row
		}
	}

	return BMParray;


}

void Image_Data::padArray(int padw, int padh){

	Pixel **temp = new Pixel*[width+padw];
	for(int i = 0; i < width+padw; i++)
	{
		temp[i] = new Pixel[height+padh];
	}

	//copy contents of old data into new data
	for(int y=0;y<height;y++){
		for(int x=0; x<width; x++){
			temp[x][y].r = data[x][y].r;
			temp[x][y].g = data[x][y].g;
			temp[x][y].b = data[x][y].b;
			temp[x][y].a = data[x][y].a;
		}
	}

	//fill extra rows/columns with white pixel colour

	//fill new columns
	if(!(padw==0)){//if width has been padded
		for(int j=0;j<height+padh;j++){
			for(int i=width; i<width+padw; i++){
				temp[i][j].r = 255;
				temp[i][j].g = 255;
				temp[i][j].b = 255;
				temp[i][j].a = 255;
			}
		}
	}

	//fill new rows
	if(!(padh==0)){//if the height has been padded
		for(int j=height;j<height+padh;j++){
			for(int i=0; i<width+padw; i++){
				temp[i][j].r = 255;
				temp[i][j].g = 255;
				temp[i][j].b = 255;
				temp[i][j].a = 255;
			}
		}
	}

	width = width+padw;
	height = height+padh;
	data = new Pixel*[width]; //reinitialise data and copy the temp array's contents into it

	for(int i = 0; i < width; i++)
	{
		data[i] = new Pixel[height];
	}

	for(int y=0;y<height;y++){
		for(int x=0; x<width; x++){
			data[x][y].r = temp[x][y].r;
			data[x][y].g = temp[x][y].g;
			data[x][y].b = temp[x][y].b;
			data[x][y].a = temp[x][y].a;
		}
	}


	for(int i = 0; i < height; i++) 
	{
		delete [] temp[i];
	}
	delete[] temp; //delete the temporary array
	
}

void Image_Data::fillArrayFromQImage(QImage* img){

	int red, blue, green, alpha;

	for(int i=0; i<width; i++){
		for(int j=0; j<height; j++){
			red = qRed(img->pixel(i,j));
			blue = qBlue(img->pixel(i,j));
			green = qGreen(img->pixel(i,j));
			alpha = qAlpha(img->pixel(i,j));
			data[i][j].r=red;	
			data[i][j].g=green;	
			data[i][j].b=blue;	
			data[i][j].a=alpha;	
		}
	}
}
