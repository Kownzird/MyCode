#include "thread.h"
#include <QDebug>

Thread::Thread(QObject *parent) : QThread(parent){}


//QThread开始一个线程，可以创建它的一个子类，然后覆盖其QThread::run()函数
void Thread::run(){
    qDebug() << "child thread id:" << QThread::currentThreadId();
    int i = 0;
    while(true){
        qDebug() << QString("Thread count %1").arg(i++);
        QThread::sleep(1);
    }
}
