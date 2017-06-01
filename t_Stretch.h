#ifndef T_STRETCH_H
#define T_STRETCH_H

#include "t_Base.h"
#include "ui_Resize.h"
#include <math.h>

#pragma once
class t_Stretch: public t_Base
{
public:
	t_Stretch(void);
	~t_Stretch(void);

	Ui::Form box;

public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
	void stretch(QString xy, Image_Data &data);
};

#endif