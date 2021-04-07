#include "student.h"
#include<QDebug>

Student::Student(QObject *parent)
	: QObject(parent)
{

}

Student::~Student()
{

}

void Student::treat()
{
	qDebug() << "treat our teacher";
}

void Student::treat(QString str)
{
	//qDebug() << "treat our teacher with" << str;  //不转为 char* 的话，输出会有引号（ treat our teacher with "noodles" ）
	qDebug() << "treat our teacher with" << str.toUtf8().data();  //转成 char* 就不会有引号了（ treat our teacher with noodles ）
}