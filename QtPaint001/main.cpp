#include "QtPaint001.h"
#include "MyScene.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setAttribute(Qt::AA_UseOpenGLES);
	QSurfaceFormat fmt;
	fmt.setSamples(4);
	QSurfaceFormat::setDefaultFormat(fmt);
	QtPaint001 w; 
	w.setWindowFlag(Qt::Window);
	w.showFullScreen();
	w.view->setSceneRect(0, 0, w.size().width(), w.size().height());
    w.show();
	return a.exec();
}
