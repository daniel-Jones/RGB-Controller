#include "controllerwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	controllerWindow w;
	w.show();

	return a.exec();
}
