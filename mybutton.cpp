#include "mybutton.h"
#include<qdebug.h>

myButton::myButton(QWidget *parent)
	: QPushButton(parent)
{
	ui.setupUi(this);
	//qDebug() << "my create" << endl;
}

myButton::~myButton()
{
	qDebug() << "my delete" << endl;
}
