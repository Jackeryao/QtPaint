#include "QtPaint001.h"
#include "MyPathItem.h"
#include <QOpenGLWidget>
#include "MyPenDialog.h"
#include <QPushButton>
#include <QSurfaceFormat>
#include <QHBoxLayout>
QtPaint001::QtPaint001(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	scene = new MyScene(this);
	scene->setSceneRect(QRectF(0, 0, 8000, 8000));
	view = new MyView(scene, this);
	setCentralWidget(view);
	view->setViewport(new QOpenGLWidget);
	view->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	view->setBackgroundBrush(Qt::white);
	setWindowTitle(tr("painter"));

	
	//退出按钮
	
	QPushButton *exitbutton = new QPushButton(this);
	exitbutton->setStatusTip(tr("exit"));
	QPixmap pixmap1("./1.png");
	exitbutton->setIcon(QIcon(pixmap1));
	exitbutton->setIconSize(pixmap1.size());
	exitbutton->setFlat(true);
	connect(exitbutton, SIGNAL(clicked()), this, SLOT(close()));
	statusBar();
	//清屏按钮
	
	QPushButton *clearbutton = new QPushButton(this);
	clearbutton->setStatusTip(tr("clear"));
	QPixmap pixmap2("./2.png");
	clearbutton->setIcon(QIcon(pixmap2));
	clearbutton->setIconSize(pixmap2.size());
	clearbutton->setFlat(true);
	connect(clearbutton, SIGNAL(clicked()), this, SLOT(SceneClear()));
	//画笔设置
	
	QPushButton *penbutton = new QPushButton(this);
	penbutton->setStatusTip(tr("pen"));
	QPixmap pixmap3("./3.png");
	penbutton->setIcon(QIcon(pixmap3));
	penbutton->setIconSize(pixmap3.size());
	penbutton->setFlat(true);
	connect(penbutton, SIGNAL(clicked()), this, SLOT(PenDialog()));
	//选择拖动模式
	selectbutton = new QPushButton(this);
	selectbutton->setStatusTip(tr("select modul"));
	QPixmap pixmap6("./6.png");
	selectbutton->setIcon(QIcon(pixmap6));
	selectbutton->setIconSize(pixmap6.size());
	selectbutton->setFlat(true);
	connect(selectbutton, SIGNAL(clicked()), this, SLOT(SelectModul()));
	//删除按钮
	QPushButton *deletebutton = new QPushButton(this);
	deletebutton->setStatusTip(tr("delete the item"));
	QPixmap pixmap7("./7.png");
	deletebutton->setIcon(QIcon(pixmap7));
	deletebutton->setIconSize(pixmap7.size());
	deletebutton->setFlat(true);
	connect(deletebutton, SIGNAL(clicked()), this, SLOT(deleteItem()));
	//缩放按钮
	QPushButton *bigbutton = new QPushButton(this);
	QPixmap pixmap4("./4.png");
	bigbutton->setIcon(QIcon(pixmap4));
	bigbutton->setIconSize(pixmap4.size());
	bigbutton->setFlat(true);
	bigbutton->setStatusTip(tr("ToBig"));
	connect(bigbutton, SIGNAL(clicked()),
		this, SLOT(BeBig()));
	
	
	QPushButton *smallbutton = new QPushButton(this);
	QPixmap pixmap5("./5.png");
	smallbutton->setIcon(QIcon(pixmap5));
	smallbutton->setIconSize(pixmap5.size());
	smallbutton->setFlat(true);
	smallbutton->setStatusTip(tr("ToSmall"));
	connect(smallbutton, SIGNAL(clicked()),
		this, SLOT(BeSmall()));
	//布局管理器
	layout = new QHBoxLayout;
	layout->addWidget(exitbutton);
	layout->addWidget(clearbutton);
	layout->addWidget(penbutton);
	layout->addWidget(selectbutton);
	layout->addWidget(deletebutton);
	layout->addWidget(bigbutton);
	layout->addWidget(smallbutton);
	setLayout(layout);
}


QtPaint001::~QtPaint001()
{
	delete scene;
	delete view;
}
QPointF QtPaint001::getViewSize()
{
	return viewSize;
}
void QtPaint001::resizeEvent(QResizeEvent *event)
{
	scene->setSceneRect(0, 0, this->width(), this->height());
	viewSize.setX(view->size().width());
	viewSize.setY(view->size().height());
	layout->setGeometry(QRect(viewSize.x() / 3, viewSize.y() - 90, viewSize.x() / 3, 80));
}
void QtPaint001::SceneClear()
{
	scene->clear();
	scene->ClearItemList();
	scene->number = 0;
}
void QtPaint001::PenDialog()
{
	MyPenDialog pen(scene->getPenColor(),
		            scene->getPenWidth(),
		            this);
	pen.exec();
}
void QtPaint001::BeBig()
{
	if (!(scene->isGroupEmpty()))
	{
		
		scene->changeGroupItemSize(1.1);
		return;
	}
	view->zoom(1.1);
}
void QtPaint001::BeSmall()
{
	if (!(scene->isGroupEmpty()))
	{
		scene->changeGroupItemSize(0.9);
		return;
	}
	view->zoom(0.9);
}
void QtPaint001::SelectModul()
{
	if (scene->getSelectModul())
	{
		QPixmap pixmap("./6.png");
		selectbutton->setIcon(QIcon(pixmap));
		selectbutton->setIconSize(pixmap.size());
		scene->setSelectModul(false);
		scene->deleteGroupOutline();
	}
	else
	{
		QPixmap pixmap("./8.png");
		selectbutton->setIcon(QIcon(pixmap));
		selectbutton->setIconSize(pixmap.size());
		scene->setSelectModul(true);
	}
}
void QtPaint001::deleteItem()
{
	if (scene->getSelectModul())
	{
		scene->destroyGroup();
	}
	return;
}