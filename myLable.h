#ifndef __MY_LABLE__
#define __MY_LABLE__

#include<qwidget.h>
#include<qlabel.h>
class MyLable : public QLabel
{
	Q_OBJECT
public:
	explicit MyLable(QWidget * parent = 0);
	~MyLable();
	virtual void enterEvent(QEvent* event);//�������¼�
	virtual void leaveEvent(QEvent* event);//����뿪
signals:
public slots:


private:

};




#endif //__MY_LABLE__