#include "mainwindow.h"
#include <QApplication>
#include"mywidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
	
	MyWidget mw;
	mw.show();

	
    return a.exec();	//��Ӧ�ó��������Ϣѭ������
}
