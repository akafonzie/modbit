#ifndef T_UNDO_H
#define T_UNDO_H

#include "t_Base.h"

#pragma once
class t_Undo: public t_Base
{
public:
	t_Undo(void);
	~t_Undo(void);
	void undoStack(Image_Data &data);

public slots:
	//It will not compile without this method - called whenever the toolbar button is pressed
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif