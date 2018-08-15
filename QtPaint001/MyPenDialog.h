#pragma once
#include <QColorDialog>
#include <QColor>
#include <QLineEdit>
#include <QStaticText>
#include <QTextEdit>
#include <QString>
#include <QDebug>
class MyPenDialog :public QColorDialog
{
public:
	MyPenDialog(const QColor& initial,const qreal& penwidth,QWidget *parent=nullptr);
	~MyPenDialog();
private:
	qreal width1;
	QLineEdit *edit;
protected:
	void accept()override;

};

