#include "mainwindow.h"
#include <QApplication>
#include"mywidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
	
	MyWidget mw;
	//mw.setParent(&w);
	mw.show();

	
    return a.exec();	//让应用程序进入消息循环机制
}
