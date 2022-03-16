#include "eventfilter.h"
#include <QEvent>
#include <QDebug>

EventFilter::EventFilter(QObject *watched, QObject *parent) : QObject(parent),m_watched(watched){}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_watched){
        if(event->type() == QEvent::MouseButtonPress){
            qDebug() << "QApplication eventFilter";
        }
    }
    return false;
}
