#include "MyView.h"
#include "MyPathItem.h"
#include "QtPaint001.h"

MyView::MyView(QGraphicsScene *scene, QWidget *parent ):QGraphicsView(scene,parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setRenderHint(QPainter::SmoothPixmapTransform);
}
void MyView::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "view is mousepress";
	QGraphicsView::mousePressEvent(event);
}
void MyView::mouseMoveEvent(QMouseEvent *event)
{
	qDebug() << "view is mousemove";
	QGraphicsView::mouseMoveEvent(event);
}
void MyView::mouseReleaseEvent(QMouseEvent *event)
{
	qDebug() << "view is mouserelease";
	QGraphicsView::mouseReleaseEvent(event);
}

void MyView::paintEvent(QPaintEvent *event)
{
	qDebug() << "View is paint";
    QGraphicsView::paintEvent(event);
}
void MyView::zoom(float scaleFactor)
{
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
	if (factor < 1 || factor > 20)
		return;

	scale(scaleFactor, scaleFactor);
}
MyView::~MyView()
{
}
