#ifndef LOAD_IMG_H
#define LOAD_IMG_H
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <stdint.h>
#include <string>
#include "Image_Data.h"

using namespace std;

struct bit_map {
    unsigned int w;
	unsigned int h;
	uint8_t* pixels;
};

class Load_Img{
public:
	int loadBMP(const char* path);
	bit_map *bmp;
	int writeBMP(const char* filename, uint8_t* pixels, int h, int w);
	int writeOther(QString filename, QString suffix, Image_Data* data);
};
#endif