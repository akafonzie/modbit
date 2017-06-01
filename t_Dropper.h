/************************************************************************************************

						t_Dropper.h - Author: Tom Weaver - 4871898
	This tool inherits from the t_Base class and adds the features relevant to the tool

*************************************************************************************************/
#ifndef T_DROPPER_H
#define T_DROPPER_H

#include "t_Base.h"

#pragma once
class t_Dropper: public t_Base
{
public:
	t_Dropper(void);
	~t_Dropper(void);
public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif