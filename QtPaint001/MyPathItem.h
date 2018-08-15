#pragma once
#include <QGraphicsPathItem>
#include "MyScene.h"
class MyPathItem :public QGraphicsPathItem
{
	
public:
	MyPathItem(const QPainterPath &path, QGraphicsItem *parent = nullptr);
	~MyPathItem();
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr)override;

};

