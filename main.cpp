#include "Main_Window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MAIN_WINDOW main_window;
	main_window.show();
	return a.exec();
}
