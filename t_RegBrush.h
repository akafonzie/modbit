#ifndef T_REGBRUSH_H
#define T_REGBRUSH_H

#include "t_Base.h"
#include "qmath.h"

#pragma once
class t_RegBrush: public t_Base
{
public:
	t_RegBrush(void);
	~t_RegBrush(void);
	void setBrushSize(int sz);
	void paint(Image_Data &data);
	void setPixelColour(Image_Data &data, int xp, int yp, int kernx, int kerny);
	void genKernel(int fsize);
	float opacity;
	float **kernel;
	int brushsize;

public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
	
};

#endif