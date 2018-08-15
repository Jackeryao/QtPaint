#include "MyPixMap.h"
#include "MyScene.h"


MyPixMap::MyPixMap(QWidget *parent) :QWidget(parent)
{
	myIsPaint = false;
	//QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect;
	//setGraphicsEffect(opacityEffect);
	//opacityEffect->setOpacity(0.7);
	//setAttribute(Qt::WA_TranslucentBackground, true);
	//QPalette pal = palette();
	//pal.setColor(QPalette::Background, QColor(0x00, 0xff, 0x00, 0x00));
    //setPalette(pal);
	//setAutoFillBackground(true);
	//setAttribute(Qt::WA_TranslucentBackground );
	//setWindowFlag(Qt::FramelessWindowHint);
	//setWindowOpacity(1);
	//setWindowOpacity(0.1);
	//setAttribute(Qt::WA_WState_WindowOpacitySet);
	setStyleSheet(" MyPixMap{ background-color:rgba(0,0,0,0%); }  ");
}
QPainterPath MyPixMap::myPath;

MyPixMap::~MyPixMap()
{
}
void MyPixMap::mousePressEvent(QMouseEvent *event)
{
	event->ignore();
	if (event->button() != Qt::LeftButton)
	{
		return;
	}
	myIsPaint = true;
	line.push_back(event->pos());
	//emit mouseEvent(0,event->pos());
	QWidget::mousePressEvent(event);

}
void MyPixMap::mouseMoveEvent(QMouseEvent *event)
{
	event->ignore();
	if (myIsPaint != true)
	{
		return;
	}

	line.push_back(event->pos());
	update();
	//emit mouseEvent(1, event->pos());
	QWidget::mouseMoveEvent(event);
}
void MyPixMap::mouseReleaseEvent(QMouseEvent *event)
{
	event->ignore();
	if (myIsPaint==false)
	{
		return;
	}
	myIsPaint = false;
	line.clear();
	//emit mouseEvent(2,event->pos());
	
	QWidget::mouseReleaseEvent(event);
}
void MyPixMap::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	//painter.setCompositionMode(QPainter::CompositionMode_Clear);
	//painter.fillRect(10, 10, 300, 300, Qt::SolidPattern);
	painter.setPen(MyScene::pen);
	painter.setRenderHint(QPainter::Antialiasing, true);
	//for (int a = 1; a < line.size(); a++)
		//painter.drawLine(line[a - 1], line[a]);
	//setWindowOpacity(0);
	//setAttribute(Qt::WA_WState_WindowOpacitySet);
	myPath = MyScene::algorithm(line);
	painter.drawPath(myPath);
}
void MyPixMap::Receivemouse1(const int type, QPointF point)
{
	switch (type) {
	case 0:
		myIsPaint = true;
		line.push_back(point);
		break;
	case 1:
		line.push_back(point);
		update();
		break;
	case 2:
		myIsPaint = false;
		line.clear();
		break;
	}
}
