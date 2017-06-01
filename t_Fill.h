/************************************************************************************************

						t_Fill.h - Author: Tom Weaver - 4871898
	This tool inherits from the t_Base class and adds the features relevant to the tool

*************************************************************************************************/
#ifndef T_FILL_H
#define T_FILL_H

#include "t_Base.h"

#pragma once
class t_Fill: public t_Base
{
public:
	t_Fill(void);
	~t_Fill(void);
public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif