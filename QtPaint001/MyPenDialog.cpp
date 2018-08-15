#include "MyPenDialog.h"
#include "QtPaint001.h"
#include "MyScene.h"
MyPenDialog::MyPenDialog(const QColor& initial,
	const qreal& penwidth,
	QWidget *parent):QColorDialog(initial,parent)
{
	width1 = penwidth;
	QTextEdit *penwidth1 = new QTextEdit("Pen Width", this);
	penwidth1->setGeometry(20, 225, 120, 25);
	penwidth1->setEnabled(false);
	edit = new QLineEdit(this);
	edit->setGeometry(110, 225, 80, 25);
	edit->setText(QString("%1").arg(width1));
}

MyPenDialog::~MyPenDialog()
{
}
void MyPenDialog::accept()
{
	int wideth = edit->text().toInt();
	if (wideth==0)
	{
		wideth = width1;
	}
	((QtPaint001*)parent())->scene->setPenWidth(wideth);
	((QtPaint001*)parent())->scene->setPenColor(currentColor());
	QDialog::accept();
}