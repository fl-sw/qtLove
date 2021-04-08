#include "mywidget.h"
#include<QPushbutton>

MyWidget::MyWidget(QWidget *parent) :
	QWidget(parent)
{
	startClass();

}

MyWidget::~MyWidget()
{

}
void MyWidget::startClass()
{
	this->teacher = new Teacher(this);
	this->student = new Student(this);
	this->setWindowTitle("this is class");
	this->resize(100, 200);

	void(Teacher:: *noPraTeacherSignal)() = &Teacher::hungry;
	void(Teacher:: *isPraTeacherSignal)(QString) = &Teacher::hungry;

	void(Student:: *noPraStudentSignal)() = &Student::treat;
	void(Student:: *isPraStudentSignal)(QString) = &Student::treat;

	//无参的 和 有参的
	connect(teacher, noPraTeacherSignal, student, noPraStudentSignal);
	connect(teacher, isPraTeacherSignal, student, isPraStudentSignal);

	QPushButton* btnOverClass = new QPushButton("class over",this);
	QPushButton* btnOverClass2 = new QPushButton("class over2", this);
	btnOverClass2->move(30, 50);
	//btnOverClass->show();

	//信号触发普通方法
	connect(btnOverClass, &QPushButton::clicked, teacher, &Teacher::classIsOver);

	//信号触发信号
	connect(btnOverClass2, &QPushButton::clicked, teacher, noPraTeacherSignal);
}
