#include "mainwindow.h"
#include "mybutton.h"
#include"myLable.h"
#include<qmenubar.h>
#include<qtoolbar.h>
#include<qstatusbar.h>
#include<qlabel.h>
#include<qtextedit.h>
#include<qdockwidget.h>
#include<qdialog.h>
#include<qmessagebox.h>
#include<qcolordialog.h>
#include<qdebug.h>
#include<qfiledialog.h>
#include<qfontdialog.h>
#include<qlistwidget.h>
#include<qtablewidget.h>
#include<qtoolbox.h>
#include<qtabwidget.h>
#include<qcombobox.h>

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
	resize(800, 400);
	
}
void MainWindow::start2()
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
	QAction* action_create = menu_file->addAction("create file");
	menu_file->addSeparator();//加一条分割线
	QAction* action_modify = menu_file->addAction("modify file");
	QAction* action_open = menu_file->addAction("open file");


	//工具栏可以有多个
	QToolBar* tb1 = new QToolBar(this);
	addToolBar(Qt::LeftToolBarArea, tb1);//添加工具栏，停靠在左侧
	tb1->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);//允许左右停靠
	tb1->setFloatable(false);//设置浮动
	tb1->setMovable(true);//设置是否可以移动
	QAction* action_paint = tb1->addAction("paint");
	QAction* action_serch = tb1->addAction("reserch");
	QAction* action_color = tb1->addAction("color");
	QAction* action_font = tb1->addAction("font");

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
	
	QDialog* dlg_create = new QDialog(this);
	dlg_create->setAttribute(Qt::WA_DeleteOnClose);
	connect(action_create, &QAction::triggered, dlg_create, &QDialog::exec);
	//dlg_create->setAttribute(Qt::WA_DeleteOnClose);//当关闭窗口后，释放掉内存、下次再点就没了


	connect(action_modify, &QAction::triggered, [=](){
		//QMessageBox::information(this, "hello", "quxiao");	
		//QMessageBox::critical(this, "critical", "warn");
		//QMessageBox::question(this, "question", "monndai", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);
		if (QMessageBox::Ok == QMessageBox::warning(this, "waring", "error", QMessageBox::Ok | QMessageBox::Ignore | QMessageBox::Cancel, QMessageBox::Ok));//parent,title,text,按钮，哪个是默认的
		{
			qDebug("selected is ok");
		}
	
	});
	connect(action_color, &QAction::triggered, [=](){
		QColor selectedColor = QColorDialog::getColor(QColor(100, 100, 100));
		qDebug() << selectedColor.red();
	}); 
	connect(action_font, &QAction::triggered, [=](){
		bool flag;
		QFont selectedFont = QFontDialog::getFont(&flag, QFont("Times", 12),this);
		qDebug() << selectedFont.pointSize();
	}); 
	connect(action_open, &QAction::triggered, [=](){
		QString filePath = QFileDialog::getOpenFileName(this, "open file", "D:\\what_is_this","(*.txt)");
		qDebug() << filePath;
	});


	
}



IndexPage::IndexPage()
{
	pageNumber = 0;
	page = new QWidget();
	page->resize(800, 500);
	page->setWindowTitle("INDEXPAGE");


	QPushButton* nextStack = new QPushButton(page);
	nextStack->move(500, 300);
	nextStack->setText("nextPage");
	nextStack->show();


	start();
	start1();
	//start2();
	page->show();

	connect(nextStack, &QPushButton::clicked, this, &IndexPage::switchStackePage);

}
void IndexPage::switchStackePage()
{
	
	void(IndexPage::*ptr[3])();
	ptr[0] = &IndexPage::start;
	ptr[1] = &IndexPage::start1;
	ptr[2] = &IndexPage::start2;
	int i = 0;
	
	(this->*ptr[pageNumber++])();
	if (pageNumber == 3)
		pageNumber = 0;

}
IndexPage::~IndexPage()
{

}
void IndexPage::start()
{
	//条目，诗词内容
	QListWidget* listContent = new QListWidget(page);
	QListWidgetItem* poent1 = new QListWidgetItem("The hut is broken by the autumn wind");
	poent1->setTextAlignment(Qt::AlignHCenter);
	listContent->addItem(poent1);
	QStringList* PoentList = new QStringList();
	*PoentList << "the first words" << "second words" << "third words";
	listContent->addItems(*PoentList);
	listContent->resize(400, 250);
	listContent->show();

	//自定义控件和事件
	MyLable *mylab = new MyLable(page);
	mylab->setText("zi dingyi biao qian");
	mylab->setFrameStyle(QFrame::Box);
	mylab->move(500, 350);
	
}
void IndexPage::start1()
{
	//表格
	QTableWidget* tableContent = new QTableWidget(page);
	tableContent->setRowCount(3);
	tableContent->setColumnCount(3);
	QStringList title;
	title << "name" << "age" << "adress";
	tableContent->setHorizontalHeaderLabels(title);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tableContent->setItem(i, j, new QTableWidgetItem("text[" + QString::number(i) + "][" + QString::number(j) + "]"));
		}
	}
	tableContent->resize(400, 250);
	tableContent->show();
}

void IndexPage::start2()
{
	//工具页面，
	QToolBox* toolbox = new QToolBox(page);
	toolbox->addItem(new QPushButton("button1", page), "add people");
	toolbox->addItem(new QPushButton("button2", page), "my note");
	toolbox->addItem(new QPushButton("button3", page), "setting");
	toolbox->addItem(new QPushButton("button4", page), "about");
	toolbox->addItem(new QLabel("weisfaofjao"), "sdfs");
	QComboBox* combox = new QComboBox(toolbox);//下拉列表
	combox->addItem("man");
	combox->addItem("felman");
	toolbox->addItem(combox, "pull down list");
	//toolbox->resize(300, 240);
	//toolbox->show();

	QToolBox* toolbox2 = new QToolBox(page);
	toolbox2->addItem(new QLabel("skdfjs"), "aaaa");
	toolbox2->addItem(new QLabel("sdfkanl"), "bbbb");
	toolbox2->addItem(new QLabel("jiunivand"), "cccc");
	toolbox2->addItem(new QLabel("vadunva"), "dddd");
	toolbox2->addItem(new QLabel("weisfaofjao"), "eeee");
	//toolbox2->resize(300, 250);
	//toolbox2->show();

	QTabWidget* tab = new QTabWidget(page);//tab页面
	tab->addTab(toolbox, "tab1");
	tab->addTab(toolbox2, "tab2");
	tab->resize(400, 240);
	tab->show();
}
