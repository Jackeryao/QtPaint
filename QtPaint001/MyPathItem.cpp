#include "MyPathItem.h"
#include "QtPaint001.h"
#include "MyScene.h"
#include <QPen>
#include <QPainter>

MyPathItem::MyPathItem(const QPainterPath &path, QGraphicsItem *parent):QGraphicsPathItem(path,parent)
{
}
MyPathItem::~MyPathItem()
{
}
void MyPathItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsPathItem::mousePressEvent(event);
}
void MyPathItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsPathItem::mouseMoveEvent(event);
}
void MyPathItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsPathItem::mouseReleaseEvent(event);
}
void MyPathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
	qDebug() << "PathItem is paint";
	QGraphicsPathItem::paint(painter, option, widget);
}