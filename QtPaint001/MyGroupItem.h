#pragma once
#include <QGraphicsItemGroup>
class MyGroupItem:public QGraphicsItemGroup
{
public:
	MyGroupItem(QGraphicsItem *parent = nullptr);
	~MyGroupItem();
	void addItem(QList<QGraphicsItem*> item);
	void removeItem(QList<QGraphicsItem*> item);
	void changeSize(float t);
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event)override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr)override;
	
};

