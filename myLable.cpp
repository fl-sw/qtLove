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
	qDebug() << "��������";
}
void MyLable::leaveEvent(QEvent* event)
{
	qDebug() << "����뿪��";
}