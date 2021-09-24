#include "mypushbutton.h"
#include <QDebug>

myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮类构造";
}

myPushButton::~myPushButton()
{
    qDebug() << "我的按钮类析构";
}
