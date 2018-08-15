#include "MyPixMapItem.h"
#include "MyScene.h"
#include <QBrush>
MyPixMapItem::MyPixMapItem(const QPixmap &pixmap, QGraphicsItem *parent ):QGraphicsPixmapItem(pixmap,parent)
{
	ispaint = false;
}

MyPixMapItem::~MyPixMapItem()
{
}

void MyPixMapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	qDebug() << "PixMapItem is begin to paint";
	if (false==((MyScene*)scene())->getItemIsPaint())
	{
		return;
	}
	if (((MyScene*)scene())->getSelectModul()==false)
	{
		painter->setPen(((MyScene*)scene())->getPen());
		painter->setRenderHint(QPainter::Antialiasing, true);
		painter->drawPath(MyScene::algorithm(((MyScene*)scene())->GetLintOR()));
	}
	else
	{
		QPen p;
		p.setWidth(1);
		p.setColor(Qt::blue);
		QBrush bursh(QColor(80, 105, 214));
		painter->setBrush(bursh);
		painter->setPen(p);
		painter->drawRect(((MyScene*)scene())->getSelectRect());
	}
	
	qDebug() << "PixMapItem is over to paint";
}
