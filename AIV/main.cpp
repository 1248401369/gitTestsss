#include "AIV.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AIV w;
	w.show();
	return a.exec();
}
