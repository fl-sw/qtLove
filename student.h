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
	//����QT����д��public slots֮�¡��߼��汾��5.4�汾�Ժ󣩿����ǳ�Ա��������ȫ�ֺ���
	//����ֵvoid�������вΣ��������أ�Ҫ������Ҫʵ��
	void treat();
	void treat(QString str);
	
};

#endif // STUDENT_H
