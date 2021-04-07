#include "teacher.h"

Teacher::Teacher(QObject *parent)
	: QObject(parent)
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