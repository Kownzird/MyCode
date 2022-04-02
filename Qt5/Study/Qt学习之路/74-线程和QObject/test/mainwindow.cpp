#include "mainwindow.h"
#include "mythread.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //QThread 对象所在的线程，和QThread 创建的线程，也就是run（）函数执行的线程不是同一个线程
    qDebug()<<"mainThread : "<<QThread::currentThreadId();

    MyThread *thread = new MyThread(this);
    thread->start();
}

MainWindow::~MainWindow()
{
}

