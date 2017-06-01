#ifndef T_PENCIL_H
#define T_PENCIL_H

#include "t_Base.h"
#include "qmath.h"

#pragma once
class t_Pencil: public t_Base
{
public:
	t_Pencil(void);
	~t_Pencil(void);
	//int size;

	void paint(Image_Data &image); 

	public slots:
		void use(Image_Data &data);
		void onPress(Image_Data &data);
};

#endif
