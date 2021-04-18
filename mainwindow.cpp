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

	//创建一个菜单栏并放进去（菜单栏最多只能有一个）
	QMenuBar* mb1 = menuBar();
	setMenuBar(mb1);
	//在菜单栏中加菜单
	QMenu* menu_file = mb1->addMenu("file");
	QMenu* menu_edit = mb1->addMenu("edit");
	QMenu* menu_view = mb1->addMenu("view");
	//在菜单项中加选项
	menu_file->addAction("create file");
	menu_file->addSeparator();//加一条分割线
	menu_file->addAction("modify file");


	//工具栏可以有多个
	QToolBar* tb1 = new QToolBar(this);
	addToolBar(Qt::LeftToolBarArea, tb1);//添加工具栏，停靠在左侧
	tb1->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);//允许左右停靠
	tb1->setFloatable(false);//设置浮动
	tb1->setMovable(true);//设置是否可以移动
	QAction* action_paint = tb1->addAction("paint");

	//状态栏
	QStatusBar* sb1 = statusBar();
	setStatusBar(sb1);
	QLabel* lable_time = new QLabel("time");
	QLabel* lable_status = new QLabel("status");
	sb1->addWidget(lable_time);
	sb1->addPermanentWidget(lable_status);


	//设置中心部件
	QTextEdit* qt1 = new QTextEdit(this);
	setCentralWidget(qt1);

	//设置铆接部件，浮动窗口
	QDockWidget* dw1 = new QDockWidget(this);
	addDockWidget(Qt::BottomDockWidgetArea, dw1);
	
}
