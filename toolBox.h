/************************************************************************************************

						toolBox.h - Author: Tom Weaver - 4871898

	This class declares the implementation of the Colour ToolBox into the project. All methods
	used by the tool are declared here and their operations defined in the toolBox.cpp.

*************************************************************************************************/
#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <qwidget.h>
#include <QToolBox>
#include <QHBoxLayout>
#include <qgridlayout.h>
#include <qtoolbutton.h>
#include <QtCore/qsignalmapper.h>
#include <qpixmap.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qslider.h>

//include class to set global colour values
#include "Image_Data.h"

#pragma once
class toolBox : public QWidget
{
	Q_OBJECT
public:
	QToolBox *theToolBox;
	int currColR, currColG, currColB, currColA;
	char currColHex;
	QLabel *currCol, *ccgLabel;
	toolBox(QWidget * parent=0);
	~toolBox(void);
private:
	QHBoxLayout *layout;
	QPixmap ccpm;
	QLineEdit *rgbedit;
	QString text;
	QSlider *hSlider;
	public slots:
		void setColour(QString qs);
	private slots:
		void addButtons();

		void addTextInput();
		void setColourCustom();
};
#endif