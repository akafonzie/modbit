//******************************************************//
//I used the following source for help with loading a   //
//BMP:                                                  //
//http://www.cplusplus.com/articles/GwvU7k9E/           //
//******************************************************//
#include "Load_Img.h"
#include "Image_Data.h"

int Load_Img::loadBMP(const char* path)
{
	
	bmp = new bit_map;
	int success = 0;
	uint8_t* dataBuffer[2]={NULL, NULL};
	uint8_t* pixels=NULL;

	BITMAPFILEHEADER* bmpHeader=NULL;
	BITMAPINFOHEADER* bmpInfo=NULL;

	//open file
	std::ifstream file(path, std::ios::binary);
	

	if(file){
		
	

	//allocate memory to hold headers
	dataBuffer[0]=new uint8_t[sizeof(BITMAPFILEHEADER)];
	dataBuffer[1]=new uint8_t[sizeof(BITMAPINFOHEADER)];

	file.read((char*)dataBuffer[0], sizeof(BITMAPFILEHEADER));
	file.read((char*)dataBuffer[1], sizeof(BITMAPINFOHEADER));

	//construct values from buffers
	bmpHeader=(BITMAPFILEHEADER*) dataBuffer[0];
	bmpInfo=(BITMAPINFOHEADER*) dataBuffer[1];

	//check that loaded file is a bitmap file
	if(bmpHeader->bfType != 0x4D42)
	{	
		MessageBox(NULL,L"Not a BMP file, please select another file!", NULL, MB_ICONEXCLAMATION);	
		success=1;
		//return ERROR;
		return success;
	}

	//allocate memory for pixels
	pixels = new uint8_t[bmpInfo->biSizeImage]; //biSizeImage is image height*image width*3 as the pixels are in a 1D array

	//start reading in image data
	file.seekg(bmpHeader->bfOffBits); //bfOffBits is the offset, in bytes, from the BITMAPFILEHEADER structure to the bitmap bits
	file.read((char*)pixels, bmpInfo->biSizeImage);

	//convert from BGR to RGB
    uint8_t tempRGB=0;
	for (unsigned long i = 0; i<bmpInfo->biSizeImage; i+=3) //size is a multiple of three so on the last iteration i is at size-3
	{
        tempRGB = pixels[i];
		pixels[i] = pixels[i+2];
        pixels[i+2] = tempRGB;
	}

	//use values loaded from file to set height and width of the image
	unsigned int w = bmpInfo->biWidth;
	unsigned int h = bmpInfo->biHeight;

	//setUpArray(pixels,w,h);
	bmp->w=w;
	bmp->h=h;
	bmp->pixels=pixels;
	return success;
	}
	else 
	{
		MessageBox(NULL,L"BMP could not found, please try again!", NULL, MB_ICONEXCLAMATION);
		//return ERROR;
		success=1;
		return success;
	}
}

int Load_Img::writeBMP(const char* filename, uint8_t* pixels, int h, int w){

	//change from RGB to BRG
    uint8_t tempBRG=0;
	int size=h*w*3;

	for (unsigned long i = 0; i<size; i+=3)
	{
        tempBRG = pixels[i];
		pixels[i] = pixels[i+2];
        pixels[i+2] = tempBRG;
	}

	//write headers
	uint8_t* dataBuffer[2]={NULL, NULL};
	
	BITMAPFILEHEADER* bmph;
	BITMAPINFOHEADER* bmpi;

	dataBuffer[0]=new uint8_t[sizeof(BITMAPFILEHEADER)]; //create empty data buffers
	dataBuffer[1]=new uint8_t[sizeof(BITMAPINFOHEADER)];

	bmph=(BITMAPFILEHEADER*) dataBuffer[0]; //copy null data buffer to headers to initialise them
	bmpi=(BITMAPINFOHEADER*) dataBuffer[1];


	bmph->bfOffBits=54;
	bmph->bfReserved1=0;
	bmph->bfReserved2=0;
	bmph->bfSize= 54 + (w*h*3); //54 = 14+40
	bmph->bfType=0x4D42; //specifies bitmap


	bmpi->biBitCount=24;
	bmpi->biClrImportant=0;
	bmpi->biClrUsed=0;
	bmpi->biCompression=0;
	bmpi->biHeight=h;
	bmpi->biPlanes=1;
	bmpi->biSize=40;
	bmpi->biSizeImage=h*w*3;
	bmpi->biWidth=w;
	bmpi->biXPelsPerMeter=0;
	bmpi->biYPelsPerMeter=0;


	//append .bmp to filename
	std::string str = filename;
	//str.append(".bmp");
	
	std::ofstream file(str, std::ofstream::binary); //create file to save bmp to

	file.write((char*)bmph, sizeof(BITMAPFILEHEADER)); //write the header files
	file.write((char*)bmpi, sizeof(BITMAPINFOHEADER));

	
	file.write((char*)pixels, bmpi->biSizeImage); //write the pixel data
	
	return 0;
	
}

int Load_Img::writeOther(QString filename, QString suffix, Image_Data* data){

	QString tmp = suffix;
	tmp = suffix.toUpper(); //make capital letters
	QByteArray ba2 = tmp.toLocal8Bit(); //convert to char array
	const char *newsuffix = ba2.data();
		

	//Create QImage object and set image format
	QImage *image = new QImage(data->width, 
	data->height,
	QImage::Format_ARGB4444_Premultiplied);

	
	for(int i=0; i < data->width; i++)
	{
		for(int j=0; j < data->height; j++)
		{
			//define a QRgb colour object as the rgba value of the current cell in the pixel array
			QRgb colour = qRgba(data->data[i][j].r,
								data->data[i][j].g,
								data->data[i][j].b,
								data->data[i][j].a);
			//assign this colour to the current pixel in the QImage
				image->setPixel(i,j,colour);
		}
	}

	image->save(filename,newsuffix,60); //save in other image format
	delete image;

	return 0;
}

