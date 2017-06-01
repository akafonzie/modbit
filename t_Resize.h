#ifndef T_RESIZE_H
#define T_RESIZE_H

#include "t_Base.h"
#include "ui_Resize.h"

#pragma once
class t_Resize: public t_Base
{
public:
	t_Resize(void);
	~t_Resize(void);

	Ui::Form box;

public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
	void resize(QString xy, Image_Data &data);
};

#endif