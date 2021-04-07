#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
	QWidget(parent)
{
	this->teacher = new Teacher(this);
	this->student = new Student(this);

	void(Teacher:: *noPraTeacherSignal)() = &Teacher::hungry;
	void(Teacher:: *isPraTeacherSignal)(QString) = &Teacher::hungry;

	void(Student:: *noPraStudentSignal)() = &Student::treat;
	void(Student:: *isPraStudentSignal)(QString) = &Student::treat;

	connect(teacher, noPraTeacherSignal, student, noPraStudentSignal);
	connect(teacher, isPraTeacherSignal, student, isPraStudentSignal);


	teacher->classIsOver();

}

MyWidget::~MyWidget()
{

}
