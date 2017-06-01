#ifndef T_RECTANGLE_H
#define T_RECTANGLE_H

#include "t_Base.h"

#pragma once
class t_Rectangle: public t_Base
{
public:
	t_Rectangle(void);
	~t_Rectangle(void);

	bool waiting;
	bool released;
	int f_x, f_y, s_x, s_y;

public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif