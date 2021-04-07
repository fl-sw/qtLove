#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include"teacher.h"
#include"student.h"

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget *parent = 0);
	~MyWidget();

private:
	Teacher* teacher;
	Student* student;
};

#endif // MYWIDGET_H
