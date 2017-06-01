#ifndef T_FLIP_H_H
#define T_FLIP_H_H

#include "t_Base.h"

#pragma once
class t_Flip_H: public t_Base
{
public:
	t_Flip_H(void);
	~t_Flip_H(void);

public slots:
	//It will not compile without this method - called whenever the toolbar button is pressed
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif