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
private:
};

#endif // MAINWINDOW_H
