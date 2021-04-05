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
	btn->setParent(this);//���ø��ף��ڸ��׵Ĵ����ϵ���
	btn->show();	//Ĭ���Զ��㴰�ڵ���ʽ�������ؼ�
	btn->setText("my_second_button");
	btn->move(100,100);
	btn->resize(120, 80);
	setWindowTitle("my_windowTitle");
	//setFixedSize(600, 400);//���ù̶��Ĵ��ڴ�С

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
