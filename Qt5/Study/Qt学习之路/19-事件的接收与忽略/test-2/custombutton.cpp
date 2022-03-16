#include "custombutton.h"
#include <QDebug>
#include <QMouseEvent>
#include <QWidget>

CustomButton::CustomButton(QWidget *parent) : QPushButton(parent){}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "CustomButton";
}


CustomButtonEx::CustomButtonEx(QWidget *parent) : CustomButton(parent){}

void CustomButtonEx::mousePressEvent(QMouseEvent *event)
{
//    event->accept(); //QEvent默认是accept的
    event->ignore();
    //忽略这个事件，事件传递到父组件（不是父类）
    //CustomButtonEx的事件传播给了父组件CustomWidget，而不是它的父类CustomButton。
    //事件的传播是在组件层次上面的，而不是依靠类继承机制。
    qDebug() << "CustomButtonEx";
}


CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent){}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    event->ignore();
//    QWidget::mousePressEvent(event);
    //QWidget的默认是调用event->ignore()
    qDebug() << "CustomWidget";
}
