#include "MyGroupItem.h"
#include <QPen>
#include <QPainter>
#include "MyPathItem.h"
#include "MyScene.h"
#include <QGraphicsPathItem>
MyGroupItem::MyGroupItem(QGraphicsItem *parent ):QGraphicsItemGroup(parent)
{
}

MyGroupItem::~MyGroupItem()
{
}
void MyGroupItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	((MyScene*)scene())->setItemIsPaint(false);
	QGraphicsItemGroup::mousePressEvent(event);
}
void MyGroupItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItemGroup::mouseMoveEvent(event);
}
void MyGroupItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	((MyScene*)scene())->setItemIsPaint(true);
	QGraphicsItemGroup::mouseReleaseEvent(event);
}
void MyGroupItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /* = nullptr */)
{
	if (isActive())
	{
		QPen p, old;
		p.setWidth(1);
		p.setColor(Qt::blue);
		old = painter->pen();
		painter->setPen(p);
		painter->drawRect(boundingRect());
		painter->setPen(old);
	}
	QGraphicsItemGroup::paint(painter, option, widget);
}
void MyGroupItem::addItem(QList<QGraphicsItem*> item)
{
	foreach(QGraphicsItem* t, item)
		addToGroup(t);
}
void MyGroupItem::removeItem(QList<QGraphicsItem*> item)
{
	foreach(QGraphicsItem* t, item)
		removeFromGroup(t);
}
void MyGroupItem::changeSize(float t)
{
	setTransformOriginPoint(boundingRect().center());
	setScale(scale()*t);
}
