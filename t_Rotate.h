#ifndef T_ROTATE_H
#define T_ROTATE_H

#include "t_Base.h"

#pragma once
class t_Rotate: public t_Base
{
public:
	t_Rotate(void);
	~t_Rotate(void);

public slots:
	//It will not compile without this method - called whenever the toolbar button is pressed
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif