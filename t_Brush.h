#ifndef T_BRUSH_H
#define T_BRUSH_H

#include "t_Base.h"
#include "qmath.h"

#pragma once
class t_Brush: public t_Base
{
public:
	t_Brush(void);
	~t_Brush(void);

	void paint(Image_Data &image); 
	void setBrushSize(int sz);
		public slots:
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif

