#include "runnable.h"
#include <QDebug>
#include <QThread>

Runnable::Runnable(){}


//QRunnable结合QThreadPoll和QThread
//都是Qt中与并发编程相关的低级接口

//QRunnable是一个轻量级的抽象类，用于开始一个另外线程的任务。
//这种任务是运行过后就丢弃的。
//由于这个类是抽象类，我们需要继承QRunnable，
//然后重写其纯虚函数QRunnable::run()

void Runnable::run(){
    qDebug() << "child thread id:" << QThread::currentThreadId();
    int i = 10;
    while (i--) {
       qDebug() << QString("hello world %1").arg(i);
    }
}
