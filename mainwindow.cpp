#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	//QPushButton* btn = new QPushButton(this);
	QPushButton* btn = new QPushButton;
	btn->setParent(this);//设置父亲，在父亲的窗口上弹出
	btn->show();	//默认以顶层窗口的形式来弹出控件
	btn->setText("my_second_button");
	btn->move(100,100);
	btn->resize(120, 80);
	setWindowTitle("my_windowTitle");
	//setFixedSize(600, 400);//设置固定的窗口大小

	myButton* mybtn = new myButton();
	mybtn->setParent(this);
	mybtn->setText("my third button");
	mybtn->move(300, 100);
	mybtn->resize(120, 80);
	mybtn->show();


	connect(btn, &QPushButton::clicked, this, &QMainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}
