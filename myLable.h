#ifndef __MY_LABLE__
#define __MY_LABLE__

#include<qwidget.h>
#include<qlabel.h>
#include<QMouseEvent>
class MyLable : public QLabel
{
	Q_OBJECT
public:
	explicit MyLable(QWidget * parent = 0);
	~MyLable();
	virtual void enterEvent(QEvent* event);//鼠标进入事件
	virtual void leaveEvent(QEvent* event);//鼠标离开
	virtual void	mouseMoveEvent(QMouseEvent * ev);
	virtual void	mousePressEvent(QMouseEvent * ev);
	virtual void	mouseReleaseEvent(QMouseEvent * ev);
signals:
public slots:


private:

};




#endif //__MY_LABLE__