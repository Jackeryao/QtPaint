#include "MyScene.h"
#include "QtPaint001.h"
#include "MyPixMap.h"
#include "MyGroupItem.h"
MyScene::MyScene(QObject *parent):QGraphicsScene(parent)
{
	pen.setWidth(6);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);
	myIsPaint = false;
	myIsPaintSelect = false;
	mypixmapItem = nullptr;
	myItemGroup = nullptr;
	number = 0;
	selectmodul = false;
	leftup.setX(0);
	leftup.setY(0);
	rightdown.setX(0);
	rightdown.setY(0);
	itemIspaint = true;
}

MyScene::~MyScene()
{
	delete mypixmapItem;
}
void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	qDebug() << "scene is mousepress";
	if (number == 0)
	{
		static QPixmap myPixmap((((QtPaint001*)parent())->getViewSize()).x(), (((QtPaint001*)parent())->getViewSize()).y());
		myPixmap.fill(Qt::transparent);
		mypixmapItem = new MyPixMapItem(myPixmap);
		addItem(mypixmapItem);
		number++;
	}
	
	if (mouseEvent->button() != Qt::LeftButton)
	{
		return;
	}
	if (selectmodul==false)
	{
		if (itemIspaint == false)
		{
			return;
		}
		myIsPaint = true;
		line.push_back(mouseEvent->scenePos());
	}
	else
	{
		if (itemIspaint == false)
		{
			return;
		}
		myIsPaintSelect = true;
		leftup = mouseEvent->scenePos();
		rightdown = mouseEvent->scenePos();
	}
	
	QGraphicsScene::mousePressEvent(mouseEvent);
}
void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	qDebug() << "scene is mousemove";
	if (selectmodul==false)
	{
		if (myIsPaint == true && itemIspaint)
	    {
		    line.push_back(mouseEvent->scenePos());
		    deletePoints();
		    updatePixmapItem();
	    }
	}
	else
	{
		if (myIsPaintSelect==true && itemIspaint)
		{
			rightdown = mouseEvent->scenePos();
			updatePixmapItem();
		}
	}
	
	QGraphicsScene::mouseMoveEvent(mouseEvent);
}
void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	qDebug() << "scene is mouserelease";
	if (selectmodul==false)
	{
		if (myIsPaint == true && itemIspaint)
		{

			MyPathItem *pathItem = new MyPathItem(algorithm(line));
			pathItem->setPen(MyScene::pen);
			addItem(pathItem);
			line.clear();
		}
		myIsPaint = false;
	}
	else
	{
		if (myIsPaintSelect==true && itemIspaint)
		{
			
			if (!selectedItem.isEmpty())
			{
				myItemGroup->removeItem(selectedItem);
				delete myItemGroup;
				selectedItem.clear();
			}
			selectedItem=items(getSelectRect());
			if (!selectedItem.isEmpty())
			{
				myItemGroup = new MyGroupItem();
				addItem(myItemGroup);
				myItemGroup->addItem(selectedItem);
				myItemGroup->setFlag(QGraphicsItem::ItemIsMovable);
			}
			
		}
		myIsPaintSelect = false;
		leftup.setX(0);
		leftup.setY(0);
		rightdown.setX(0);
		rightdown.setY(0);
		updatePixmapItem();

	}
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
void MyScene::setPenColor(const QColor& c)
{
	pen.setColor(c);
}
void MyScene::setPenWidth(const qreal& w)
{
	pen.setWidth(w);
}
const QColor& MyScene::getPenColor()
{
	return pen.color();
}
qreal MyScene::getPenWidth()
{
	return pen.width();
}
const QPen& MyScene::getPen()
{
	return pen;
}
void MyScene::updatePixmapItem()
{
	mypixmapItem->update();
}
const QVector<QPointF> & MyScene::GetLintOR()
{
	return line;
}
void MyScene::ClearLine()
{
	line.clear();
}
void MyScene::ClearItemList()
{
	selectedItem.clear();
}
void MyScene::setSelectModul(bool b)
{
	selectmodul = b;
}
bool MyScene::getSelectModul()
{
	return selectmodul;
}
void MyScene::changeGroupItemSize(float t)
{
	if (selectedItem.isEmpty())
	{
		return;
	}
	myItemGroup->changeSize(t);
	
	
}
bool MyScene::isGroupEmpty()
{
	return selectedItem.isEmpty();
}
QRectF MyScene::getSelectRect()
{
	if (leftup.x()<=rightdown.x())
	{
		if (leftup.y()<=rightdown.y())
		{
			return QRectF(leftup, rightdown);
		}
		else
		{
			return QRectF(leftup.x(), rightdown.y(), rightdown.x() - leftup.x(), leftup.y() - rightdown.y());
		}
	}
	else
	{
		if (leftup.y()<=rightdown.y())
		{
			return QRectF(rightdown.x(), leftup.y(), leftup.x() - rightdown.x(), rightdown.y() - leftup.y());
		}
		else
		{
			return QRectF(rightdown, leftup);
		}
	}
}
void MyScene::deleteGroupOutline()
{
	myItemGroup->removeItem(selectedItem);
	selectedItem.clear();
}
void MyScene::destroyGroup()
{
	myItemGroup->removeItem(selectedItem);
	for each (QGraphicsItem* t in selectedItem)
	{
		removeItem(t);
		delete t;
	}
	selectedItem.clear();
}
void MyScene::setItemIsPaint(bool b)
{
	itemIspaint = b;
}
bool MyScene::getItemIsPaint()
{
	return itemIspaint;
}
void MyScene::deletePoints()
{
	if (line.count() > 3) {
		QVector<QPointF>::iterator i = line.end();
		if (abs((*(i - 1)).x() - (*(i - 2)).x()) + abs((*(i - 1)).y() - (*(i - 2)).y()) < 5)
			line.erase(i - 1);
	}
}

float bezier3funcX(float uu, QPointF *controlP) {
	float part0 = controlP[0].x() * uu * uu * uu;
	float part1 = 3 * controlP[1].x() * uu * uu * (1 - uu);
	float part2 = 3 * controlP[2].x() * uu * (1 - uu) * (1 - uu);
	float part3 = controlP[3].x() * (1 - uu) * (1 - uu) * (1 - uu);
	return part0 + part1 + part2 + part3;
}
float bezier3funcY(float uu, QPointF *controlP) {
	float part0 = controlP[0].y() * uu * uu * uu;
	float part1 = 3 * controlP[1].y() * uu * uu * (1 - uu);
	float part2 = 3 * controlP[2].y() * uu * (1 - uu) * (1 - uu);
	float part3 = controlP[3].y() * (1 - uu) * (1 - uu) * (1 - uu);
	return part0 + part1 + part2 + part3;
}
QPainterPath  MyScene::algorithm(const QVector<QPointF> & originPoint) {
	QPainterPath path;
	int originCount = originPoint.size();
	float scale = 0.6;
	std::vector<QPointF> midpoints(originCount + 6);
	//生成中点   
	double x, y;
	for (int i = 0; i < originCount; i++) {
		int nexti = i + 1;
		if (nexti == originCount)
			nexti = originCount - 1;
		x = (originPoint[i].x() + originPoint[nexti].x()) / 2.0;
		y = (originPoint[i].y() + originPoint[nexti].y()) / 2.0;
		midpoints[i] = QPointF(x, y);
	}

	//平移中点  
	std::vector<QPointF> additionalPoints(originCount * 2 + 5);
	for (int i = 0; i < originCount; i++) {
		int nexti = i + 1;
		if (nexti == originCount)
			nexti = originCount - 1;
		int backi = i - 1;
		if (backi < 0) backi = 0;

		x = (midpoints[i].x() + midpoints[backi].x()) / 2.0;
		y = (midpoints[i].y() + midpoints[backi].y()) / 2.0;
		int offsetx = originPoint[i].x() - x;
		int offsety = originPoint[i].y() - y;

		//移动得到更多的曲线上点的控制点
		int index = 2 * i;
		additionalPoints[index] = QPointF(midpoints[backi].x() + offsetx, midpoints[backi].y() + offsety);
		int addx = (additionalPoints[index].x() - originPoint[i].x()) * scale;
		int addy = (additionalPoints[index].y() - originPoint[i].y()) * scale;
		additionalPoints[index] = QPointF(originPoint[i].x() + addx, originPoint[i].y() + addy);

		int nextIndex = index + 1;
		additionalPoints[nextIndex] = QPointF(midpoints[i].x() + offsetx, midpoints[i].y() + offsety);
		addx = (additionalPoints[nextIndex].x() - originPoint[i].x()) * scale;
		addy = (additionalPoints[nextIndex].y() - originPoint[i].y()) * scale;
		additionalPoints[nextIndex] = QPointF(originPoint[i].x() + addx, originPoint[i].y() + addy);
	}

	QPointF controlPoint[4];
	//生成控制点，产生贝塞尔曲线  
	for (int i = 0; i < originCount - 1; i++) {
		controlPoint[0] = originPoint[i];
		int index = 2 * i;
		controlPoint[1] = additionalPoints[index + 1];
		int nextIndex = index + 2;
		controlPoint[2] = additionalPoints[nextIndex];
		int nexti = i + 1;
		if (nexti == originCount)
			nexti = originCount - 1;
		controlPoint[3] = originPoint[nexti];

		double t = abs(controlPoint[0].x() - controlPoint[3].x()) + abs(controlPoint[0].y() - controlPoint[3].y());
		t = 20 / t;
		float u = 1;
		while (u >= 0) {
			int px = bezier3funcX(u, controlPoint);
			int py = bezier3funcY(u, controlPoint);
			//u的步长决定曲线的疏密  
			u -= t;
			QPointF tempP = QPointF(px, py);
			if (i == 0) path.moveTo(tempP);
			else path.lineTo(tempP);
		}
	}
	return path;
}

