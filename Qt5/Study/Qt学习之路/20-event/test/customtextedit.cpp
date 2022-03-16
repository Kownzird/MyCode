#include "customtextedit.h"
#include <QKeyEvent>
#include <QEvent>
#include <QDebug>

CustomTextEdit::CustomTextEdit(QWidget *parent) : QTextEdit(parent)
{

}

bool CustomTextEdit::event(QEvent *e)
{
    if(e->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if(keyEvent->key() == Qt::Key_Tab){
            qDebug() << "You press tab";
            return true;
        }
    }
    //重写了其event()函数，却没有调用父类的同名函数。
    //组件就只能处理 Tab 键，再也无法输入任何文本，也不能响应其它事件
    return false;
//    return QTextEdit::event(e);
}
