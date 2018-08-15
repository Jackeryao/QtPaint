#pragma once
#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <vector>
#include <QPen>
#include <QPainter>
#include <QPalette>
#include <QGraphicsScene>
#include <QGraphicsOpacityEffect>
class MyPixMap : public QWidget
{
	Q_OBJECT
public:
	MyPixMap(QWidget *parent = Q_NULLPTR);
	~MyPixMap();

protected:
	void mousePressEvent(QMouseEvent *event)override;
	void mouseMoveEvent(QMouseEvent *event)override;
	void mouseReleaseEvent(QMouseEvent *event)override;
	void paintEvent(QPaintEvent *event)override;
private:
	bool myIsPaint;
	QVector<QPointF> line;
	QPen pen;
public:
	static QPainterPath myPath;
signals:
	void mouseEvent(const int type,QPointF point);
public:
	void Receivemouse1(const int type, QPointF point);
};

