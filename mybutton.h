#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include "ui_mybutton.h"

class myButton : public QPushButton
{
	Q_OBJECT

public:
	myButton(QWidget *parent = 0);
	~myButton();

private:
	Ui::myButton ui;
};

#endif // MYBUTTON_H
