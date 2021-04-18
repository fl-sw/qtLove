#include "mainwindow.h"
#include "mybutton.h"
#include<qmenubar.h>
#include<qtoolbar.h>
#include<qstatusbar.h>
#include<qlabel.h>
#include<qtextedit.h>
#include<qdockwidget.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{	
	start();
}

MainWindow::~MainWindow()
{
}

void MainWindow::start()
{
	resize(500, 400);

	//����һ���˵������Ž�ȥ���˵������ֻ����һ����
	QMenuBar* mb1 = menuBar();
	setMenuBar(mb1);
	//�ڲ˵����мӲ˵�
	QMenu* menu_file = mb1->addMenu("file");
	QMenu* menu_edit = mb1->addMenu("edit");
	QMenu* menu_view = mb1->addMenu("view");
	//�ڲ˵����м�ѡ��
	menu_file->addAction("create file");
	menu_file->addSeparator();//��һ���ָ���
	menu_file->addAction("modify file");


	//�����������ж��
	QToolBar* tb1 = new QToolBar(this);
	addToolBar(Qt::LeftToolBarArea, tb1);//��ӹ�������ͣ�������
	tb1->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);//��������ͣ��
	tb1->setFloatable(false);//���ø���
	tb1->setMovable(true);//�����Ƿ�����ƶ�
	QAction* action_paint = tb1->addAction("paint");

	//״̬��
	QStatusBar* sb1 = statusBar();
	setStatusBar(sb1);
	QLabel* lable_time = new QLabel("time");
	QLabel* lable_status = new QLabel("status");
	sb1->addWidget(lable_time);
	sb1->addPermanentWidget(lable_status);


	//�������Ĳ���
	QTextEdit* qt1 = new QTextEdit(this);
	setCentralWidget(qt1);

	//����í�Ӳ�������������
	QDockWidget* dw1 = new QDockWidget(this);
	addDockWidget(Qt::BottomDockWidgetArea, dw1);
	
}
