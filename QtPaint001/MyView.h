#pragma once
#include <QGraphicsView>
#include <vector>
#include <QPointF>
#include <QMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
class MyView:public QGraphicsView
{
public:
	MyView(QGraphicsScene *scene, QWidget *parent = nullptr);
	~MyView();
	void zoom(float scaleFactor);
protected:
	void mousePressEvent(QMouseEvent *event)override;
	void mouseMoveEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;
	void paintEvent(QPaintEvent *event)override;
private:
	
};

