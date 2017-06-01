#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H
#include <stdint.h>
#include <qvector2d.h>
#include <qvector.h>
#include <qstack.h>
#include <qlabel.h>

#pragma once

struct Pixel {
    int r, g, b, a;
};

class Image_Data
{
public:
	Image_Data(void);
	~Image_Data(void);

	int width, height, cursor_x, cursor_y, prevcursor_x, prevcursor_y, vec, intPoint;
	bool mouse_press, mouse_release, mouse_drag, interp, dropper;
	QVector2D vec1, vec2;
	QVector<QVector2D> intVec;
	Pixel colour;

	Pixel **data;

	uint8_t* arrayToBMP(void);
	void padArray(int padw, int padh);
	void fillArray(void);
	void fillArrayFromImage(uint8_t* pixels);
	void fillArrayFromQImage(QImage* img);
	void setDimensions(int new_width, int new_height);
	void setPixel(int x, int y);
	void setPixel(int x, int y, int pr, int pg, int pb);
	Pixel getPixel(int x, int y);
};

#endif

