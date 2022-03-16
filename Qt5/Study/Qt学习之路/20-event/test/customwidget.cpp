#include "customwidget.h"
#include <QKeyEvent>
#include <QDebug>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{

}

bool CustomWidget::event(QEvent *e)
{
    if(e->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if(keyEvent->key() == Qt::Key_Tab){
            qDebug() << "You press tab";

            //如果传入的事件已被识别并且处理，则需要返回 true
            return true;
        }
    }
    return QWidget::event(e);
}
