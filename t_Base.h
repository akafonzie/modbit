#ifndef T_BASE_H
#define T_BASE_H

#include <QtWidgets/QMainWindow>

#include "Image_Data.h"
#pragma once
class t_Base
{
	public:
		t_Base(void);
		~t_Base(void);
		int size;
		bool toolChanged;
		const char* icon; 
		const char* tooltip;
		const char* shortcut;
		QString id;
		void setToolSize(int sz);
	public slots:
		virtual void use(Image_Data &data) = 0;
		virtual void onPress(Image_Data &data) = 0;
};

#endif

