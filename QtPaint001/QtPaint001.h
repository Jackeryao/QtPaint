#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtPaint001.h"
#include "MyScene.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <vector>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <QAction>
#include "MyPixMap.h"
#include "MyView.h"
#include <QHBoxLayout>
class QtPaint001 : public QMainWindow
{
	Q_OBJECT
public:
	QtPaint001(QWidget *parent = Q_NULLPTR);
	~QtPaint001();
	QPointF getViewSize();
protected:
	void resizeEvent(QResizeEvent *event)override;
private:
	Ui::QtPaint001Class ui; 
	QPointF viewSize;
	QHBoxLayout *layout;
	QPushButton *selectbutton;
public:
	MyScene * scene;
	MyView *view;
private slots:
	void SceneClear();
    void PenDialog();
    void BeBig();
	void BeSmall();
	void SelectModul();
	void deleteItem();
};
