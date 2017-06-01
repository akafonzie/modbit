#pragma once
#ifndef T_GREYSCALE_H
#define T_GREYSCALE_H


#include "t_Base.h"

class t_Greyscale: public t_Base
{
public:
	t_Greyscale(void);
	~t_Greyscale(void);

	public slots:
		void use(Image_Data &data);
		void onPress(Image_Data &data);
};

#endif