#ifndef T_MIRROR_H
#define T_MIRROR_H

#include "t_Base.h"

#pragma once
class t_Mirror: public t_Base
{
public:
	t_Mirror(void);
	~t_Mirror(void);

public slots:
	//It will not compile without this method - called whenever the toolbar button is pressed
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif