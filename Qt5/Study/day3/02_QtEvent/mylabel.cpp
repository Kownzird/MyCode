#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪状态
    setMouseTracking(true);
}



void myLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入了";
}

void myLabel::leaveEvent(QEvent *event)
{
   qDebug() << "鼠标离开了";
}

//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下了 x=%1 y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::RightButton)
    {
        QString str = QString("鼠标释放了 x=%1 y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
//    //鼠标按住左键移动时打印信息
//    if(ev->buttons() & Qt::LeftButton)
//    {
//        QString str = QString("鼠标移动了 x=%1 y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
//        qDebug() << str;
//    }

    //设置鼠标追踪，不需按下即可打印信息
    QString str = QString("鼠标移动了 x=%1 y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}


bool myLabel::event(QEvent *e)
{
    //如果是鼠标按下，在event事件分发中做拦截操作
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* ev = static_cast<QMouseEvent*>(e);
        QString str = QString("Event函数中：：鼠标按下了x=%1 y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
        return true; //true代表用户自己处理这个事件，不向下分发
    }

    //其他事件交给类处理，默认处理
    return QLabel::event(e);

}
