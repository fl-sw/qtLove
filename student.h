#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include"teacher.h"

class Student : public QObject
{
	Q_OBJECT

public:
	Student(QObject *parent);
	Student();
	~Student();

private:
	QString qstr;
	Teacher teacher;
signals:

public slots:
	//����QT����д��public slots֮�¡��߼��汾��5.4�汾�Ժ󣩿����ǳ�Ա��������ȫ�ֺ���
	//����ֵvoid�������вΣ��������أ�Ҫ������Ҫʵ��
	void treat();
	void treat(QString str);
	
};

#endif // STUDENT_H
