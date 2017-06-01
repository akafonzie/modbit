#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qtoolbutton.h>
#include <QtCore/qtimer.h>
#include <QtCore/qsignalmapper.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qlabel.h>
#include <qfiledialog.h>
#include <qgraphicsitem.h>
#include <qslider.h>
#include <qstack.h>
#include <cstring>
#include "Load_Img.h"

//TOOL INCLUDES
#include "t_Blur.h"
#include "t_Brush.h"
#include "t_RegBrush.h"
#include "t_Pencil.h"
#include "t_Greyscale.h"
//#include "t_Undo.h"
//#include "t_Redo.h"
#include "t_Rotate.h"
#include "t_Dropper.h"
#include "t_Rectangle.h"
#include "t_Flip_H.h"
#include "t_Flip_V.h"
#include "t_Mirror.h"
#include "t_Resize.h"
#include "t_Stretch.h"
#include "t_Example.h"
#include "t_Fill.h"
#include "t_Eraser.h"
#include "t_Line.h"
#include "t_threeDLine.h"
#include "toolBox.h"


#include "ui_Main_Window.h"

#define HEIGHT			640
#define WIDTH			480
#define MAX_TOOLS		100

struct Tool {
    QString id;
	t_Base* tool;
};

typedef void (*fP)();
class MAIN_WINDOW : public QMainWindow
{
	Q_OBJECT

	public:
		MAIN_WINDOW(QWidget *parent = 0);
		~MAIN_WINDOW();
		
	private:
		Ui::MAIN_WINDOWClass ui;
		QPoint cursor;
		QImage* image;
		QTimer *update_timer;
		QSlider *szSlider;
		QVector <QLabel*> tempvec;
		int x, temp;
		bool change, just_released, interp, first_run, draw;

		Image_Data data; 
		
		void closeEvent(QCloseEvent *event);

		void mousePressEvent(QMouseEvent *m);
		void mouseReleaseEvent(QMouseEvent *m);
		void initialise();
		void update(QLabel *label);

		void updateCursor(void);
		void initToolbar(void);
		void addToolButton(t_Base* tool);
		void setGlobalColour();
		void regTool(Tool newTool);

		Tool* tool_Array;
		t_Base* active_tool;
		toolBox theToolBox;
		
		
	private slots:
		void refresh();
		void addSizeSlider();
		void setToolSize(int sz);
		void linkTool(QString id);
		void getImage();
		void drawImage();
		void save();
		
	public slots:

		void colourPicker();
	
};

#endif // MAIN_WINDOW_H
