#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT //�꣬��������ʹ���źźͲۻ���

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	void start();
	void start2();
private:
};

class IndexPage : public QObject
{
	Q_OBJECT //�꣬��������ʹ���źźͲۻ���

public:
	IndexPage();
	~IndexPage();
	void start();
	void start1();
	void start2();
	void start3();
	void start4();
	void start5();
public slots:
	void switchStackePage();

private:
	QWidget* page;
	int pageNumber;
};

#endif // MAINWINDOW_H
