#ifndef T_REDO_H
#define T_REDO_H

#include "t_Base.h"

#pragma once
class t_Redo: public t_Base
{
public:
	t_Redo(void);
	~t_Redo(void);

public slots:
	//It will not compile without this method - called whenever the toolbar button is pressed
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif