#include "custombutton.h"
#include <QDebug>
#include <QMouseEvent>

CustomButton::CustomButton(QWidget *parent) : QPushButton(parent)
{
    connect(this, &CustomButton::clicked, this,&CustomButton::onClickButton);
}

void CustomButton::onClickButton()
{
    qDebug() << "You click this";
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        qDebug() << "Left";
    } else {
        QPushButton::mousePressEvent(event);
    }
}
