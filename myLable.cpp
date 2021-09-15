#include"myLable.h"
#include<qdebug.h>


MyLable::~MyLable()
{
}

MyLable::MyLable(QWidget * parent):QLabel(parent)
{

}

void MyLable::enterEvent(QEvent* event)
{
	qDebug() << "鼠标进来了";
}
void MyLable::leaveEvent(QEvent* event)
{
	qDebug() << "鼠标离开了";
}