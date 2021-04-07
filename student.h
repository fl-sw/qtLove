#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
	Q_OBJECT

public:
	Student(QObject *parent);
	~Student();

private:

signals:

public slots:
	//早期QT必须写到public slots之下。高级版本（5.4版本以后）可以是成员函数或者全局函数
	//返回值void，可以有参，可以重载，要声明，要实现
	void treat();
	void treat(QString str);
	
};

#endif // STUDENT_H
