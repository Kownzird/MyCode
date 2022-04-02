#include "mythread.h"
#include <QDebug>

MyThread::MyThread(QObject *parent) : QThread(parent){

    otherObj = new QObject;
    qDebug()<<"MyThreadobject currentThreadId :"<< QThread::currentThreadId();

}


void MyThread::run(){
    qDebug()<<"run()  currentThreadId : "<<QThread::currentThreadId();
    //Qt 要求QObject的所有子对象都必须和其父对象在同一线程
    //Qt 还要求，在代表一个线程的QThread对象销毁之前，所有在这个线程中的对象都必须先delete，解决：在QThread::run()的栈上创建对象即可

    //1. 不能对有父对象（parent 属性）的对象使用QObject::moveToThread()函数
    //2. 不能在QThread中以这个QThread本身作为父对象创建对象，因为QThread对象所依附的线程是创建它的那个线程，与创建的obj不在同一个线程
    QObject *obj2 = new QObject(this); //错误


    //QMetaObject::invokeMethod(object, "methodName",
    //                          Qt::QueuedConnection,
    //                          Q_ARG(type1, arg1),
    //                          Q_ARG(type2, arg2));
//    Qt::DirectConnection：直接连接意味着槽函数将在信号发出的线程直接调用
//    Qt::QueuedConnection：队列连接意味着向接受者所在线程发送一个事件，该线程的事件循环将获得这个事件，然后之后的某个时刻调用槽函数
//    Qt::BlockingQueuedConnection：阻塞的队列连接就像队列连接，但是发送者线程将会阻塞，直到接受者所在线程的事件循环获得这个事件，槽函数被调用之后，函数才会返回
//    Qt::AutoConnection：自动连接（默认）意味着如果接受者所在线程就是当前线程，则使用直接连接；否则将使用队列连接
    MyThread thread;
    Object obj;
    QObject::connect(&thread, SIGNAL(aSignal()), &obj, SLOT(aSlot()));
    thread.start();
}
