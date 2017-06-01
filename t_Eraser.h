/************************************************************************************************

						t_Eraser.h - Author: Tom Weaver - 4871898
	This tool inherits from the t_Base class and adds the features relevant to the tool

*************************************************************************************************/
#ifndef T_ERASER_H
#define T_ERASER_H

#include "t_Base.h"

#pragma once
class t_Eraser: public t_Base
{
public:
	t_Eraser(void);
	~t_Eraser(void);
public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
	void setSize(int sz);
};

#endif