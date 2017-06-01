#ifndef T_BLUR_H
#define T_BLUR_H

#include "t_Base.h"

#pragma once
class t_Blur : public t_Base
{
public:
	t_Blur(void);
	~t_Blur(void);
	void blurPixels(Image_Data &image);
	void getBlurVals(float temp_rgb_vals[], Image_Data &image);
	void setBlurVals(float temp_rgb_vals[], Image_Data &image);
	void setBrushSize(int sz);
public slots:
	void use(Image_Data &data);	
	void onPress(Image_Data &data);
};

#endif