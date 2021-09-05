#include "teacher.h"
#include<qstring.h>

Teacher::Teacher(QObject *parent)
	: QObject(parent)
{

}
Teacher::Teacher()
{

}

Teacher::~Teacher()
{

}

void Teacher::classIsOver()
{
	emit this->hungry();
	emit this->hungry("noodles");
}

void Teacher::order(QString qstr)
{
	//QString qstr ="dumplings";
	emit this->hungry(qstr);
}