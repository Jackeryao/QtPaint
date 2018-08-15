#pragma once
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
class MyPixMapItem:public QGraphicsPixmapItem
{
public:
	MyPixMapItem(const QPixmap &pixmap,QGraphicsItem *parent = nullptr);
	~MyPixMapItem();
private:
	bool ispaint;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr)override;

};

