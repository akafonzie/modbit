#ifndef T_EXAMPLE_H
#define T_EXAMPLE_H

#include "t_Base.h"

#pragma once
class t_Example: public t_Base
{
public:
	t_Example(void);
	~t_Example(void);

public slots:
	/*It will not compile without these methods - called whenever the tool is used 
	or the toolbar button is pressed*/
	void use(Image_Data &data);
	void onPress(Image_Data &data);
};

#endif