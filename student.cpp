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
	//qDebug() << "treat our teacher with" << str;  //��תΪ char* �Ļ�������������ţ� treat our teacher with "noodles" ��
	qDebug() << "treat our teacher with" << str.toUtf8().data();  //ת�� char* �Ͳ����������ˣ� treat our teacher with noodles ��
}