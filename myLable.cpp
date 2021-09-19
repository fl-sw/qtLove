#include"myLable.h"
#include<qdebug.h>


MyLable::~MyLable()
{
}

MyLable::MyLable(QWidget * parent):QLabel(parent)
{
	setMouseTracking(true);
}

//�������¼�
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
	if (ev->buttons() & Qt::LeftButton)//ֻ����������Ϊ�����жཨ��ϣ�����Ҫ��buttons()
	{
		//����ڵ�ǰ��ǩ��λ�� ����Ļ��λ��
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