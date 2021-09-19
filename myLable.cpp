#include"myLable.h"
#include<qdebug.h>


MyLable::~MyLable()
{
}

MyLable::MyLable(QWidget * parent):QLabel(parent)
{
	setMouseTracking(true);
}

//鼠标进入事件
void MyLable::enterEvent(QEvent* event)
{
	qDebug() << "enter";
}
void MyLable::leaveEvent(QEvent* event)
{
	qDebug() << "leave";
}

void MyLable::mouseMoveEvent(QMouseEvent * ev)
{
	if (ev->buttons() & Qt::LeftButton)//只监控左键，因为可以有多建组合，所以要用buttons()
	{
		//鼠标在当前标签的位置 在屏幕的位置
		QString str = QString("move-> x=%1 y=%2 globalX=%3 globalY=%4 ").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
		qDebug() << str;
	}
}
void MyLable::mousePressEvent(QMouseEvent * ev)
{
	if (ev->button() == Qt::LeftButton)
		qDebug() << "press";
}
void MyLable::mouseReleaseEvent(QMouseEvent * ev)
{
	if (ev->button() == Qt::LeftButton)
		qDebug() << "release";
}