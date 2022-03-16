#include "qtcustomevent.h"
#include "customevent.h"
#include <QSpinBox>
#include <QApplication>
#include <QDebug>
#include <QEvent>

QtCustomEvent::QtCustomEvent(QApplication *pApp, QWidget *parent) : QMainWindow(parent),m_pApp(pApp)
{
    this->resize(300,200);

    QSpinBox *spinBox = new QSpinBox(this);
    spinBox->resize(100,50);
    spinBox->move(100,75);
    spinBox->show();

    void (QSpinBox::*valueChangedInt)(int) = &QSpinBox::valueChanged;
    connect(spinBox, valueChangedInt,[=](){
        int value = spinBox->value();

        //发送事件
        ChangeNumberEvent e(this, value);
        m_pApp->sendEvent(this, &e);

        //static bool QCoreApplication::sendEvent(QObject *receiver, QEvent *event);
        //在事件被发送的时候，event对象并不会被销毁。通常我们会在栈上创建event对象

        //static void QCoreApplication::postEvent(QObject *receiver, QEvent *event);
        //post 事件队列会持有事件对象，并且在其 post 的时候将其 delete 掉，因此必须在堆上创建event对象
    });

}

void QtCustomEvent::customEvent(QEvent *event)
{
    ChangeNumberEvent *changeEvent = dynamic_cast<ChangeNumberEvent *>(event);
    qDebug() << "Value Change Event in EventHandle Function:" << changeEvent->m_nNumber;
}

bool QtCustomEvent::event(QEvent *event)
{
    if(event->type() == ChangeNumberEventID){
        ChangeNumberEvent *changeEvent = dynamic_cast<ChangeNumberEvent *>(event);
        qDebug() << "Value Change Event in Event Function:" << changeEvent->m_nNumber;
        return true;
    }
    return QWidget::event(event);
}
