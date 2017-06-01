#include "t_Base.h"


t_Base::t_Base(void)
{
	icon = "/icons/blank.png";
	tooltip = "Add Tooltip Here";
	shortcut = "";
	id = "CHANGEME";
	size = 5;
	toolChanged = true;
}


t_Base::~t_Base(void)
{
}

void t_Base::setToolSize(int sz)
{
	size = sz;
}
