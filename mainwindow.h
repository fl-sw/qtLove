#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT //宏，允许类中使用信号和槽机制

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	void start();
private:
};

#endif // MAINWINDOW_H
