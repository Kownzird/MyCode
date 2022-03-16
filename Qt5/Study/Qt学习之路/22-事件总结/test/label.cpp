#include "label.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

Label::Label(QWidget *parent)
    : QWidget(parent)
{
    installEventFilter(this);
}

Label::~Label()
{
}

bool Label::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this){
        if(event->type() == QEvent::MouseButtonPress){
            qDebug() << "eventFilter";
        }
    }
    return false;
}

void Label::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
}

bool Label::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        qDebug() << "event " << mouseEvent->button();
    }
    return QWidget::event(event);
}

