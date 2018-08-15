#pragma once
#include <QGraphicsScene>
#include <QPainterPath>
#include <QPen>
#include <QFont>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <MyPathItem.h>
#include <QPoint>
#include <QDebug>
#include <QPixmap>
#include <iostream>
#include <QColor>
#include "MyPixMapItem.h"
#include "MyPixMapItem.h"
#include <QRectF>
#include "MyGroupItem.h"
#include <QList>

class MyScene : public QGraphicsScene
{
	Q_OBJECT
public:
	MyScene(QObject *parent =0);
	~MyScene();
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
public:
	static QPainterPath algorithm(const QVector<QPointF> &Pnts);
	const QVector<QPointF> & GetLintOR();
	void ClearLine();
	void ClearItemList();
	void setPenWidth(const qreal& w);
	void setPenColor(const QColor& c);
	const QColor& getPenColor();
	qreal getPenWidth();
	const QPen& getPen();
	void updatePixmapItem();
	void deletePoints();
	void setSelectModul(bool b);
	bool getSelectModul();
	QRectF getSelectRect();
	void deleteGroupOutline();
	void destroyGroup();
	void setItemIsPaint(bool b);
	bool getItemIsPaint();
	void changeGroupItemSize(float t);
	bool isGroupEmpty();
private:
	QPainterPath * myPath;
	QVector<QPointF> line; 
	bool myIsPaint,myIsPaintSelect;
	QPen pen;
	MyPixMapItem *mypixmapItem;
	bool selectmodul;
	QPointF leftup, rightdown;
	MyGroupItem *myItemGroup;
	QList<QGraphicsItem*> selectedItem;
	bool itemIspaint;
public:
	int number;
	
};

