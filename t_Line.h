#ifndef T_LINE_H
#define T_LINE_H

#include "t_Base.h"
#include "qmath.h"


#pragma once
class t_Line: public t_Base
{
public:
	t_Line(void);
	~t_Line(void);

	void draw(Image_Data &image); 
	void setBrushSize(int sz);
	void calcLinePoints(int x1, int y1, int x2, int y2);
	void calcLinePointsSteep(int x1, int y1, int x2, int y2);
	QVector<QVector2D> linePoints;
	bool justClicked;
	int start_x, start_y, end_x, end_y;
	void swap(int n1, int n2);

public slots:
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif

