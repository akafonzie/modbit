/************************************************************************************************

						t_threeDLine.h - Author: Tom Weaver - 4871898
	This tool inherits from the t_Base class and adds the features relevant to the tool

*************************************************************************************************/
#ifndef T_THREEDLINE_H
#define T_THREEDLINE_H

#include "t_Base.h"

#pragma once
class t_threeDLine: public t_Base
{
public:
	t_threeDLine(void);
	~t_threeDLine(void);

	//void findColAv(Image_Data &data);
public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	int dir;
	void draw(Image_Data &data, int x, int y);
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif