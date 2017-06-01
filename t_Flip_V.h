#ifndef T_FLIP_V_H
#define T_FLIP_V_H

#include "t_Base.h"

#pragma once
class t_Flip_V: public t_Base
{
public:
	t_Flip_V(void);
	~t_Flip_V(void);

public slots:
	//It will not compile without this method - called whenever the toolbar button is pressed
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif