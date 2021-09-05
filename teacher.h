#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
	Q_OBJECT

public:
	Teacher(QObject *parent);
	Teacher();
	~Teacher();
	void classIsOver();
private:

signals :
	void hungry();//只需要声明，不要实现
	void hungry(QString str);


public slots:
	void order(QString qstr);

private:
	int i;
};

#endif // TEACHER_H
