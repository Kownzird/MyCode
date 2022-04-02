#include "mainwindow.h"
#include "thread.h"
#include "runnable.h"
#include <QDebug>
#include <QThreadPool>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "main thread id is" << QThread::currentThreadId();

    //QThread类
//    Thread *thread = new Thread;
//    //使用start开始新的线程
//    thread->start();

    //QRunnable和QThreadPool类
    //QThreadPool类开启一个Runnable对象
    //所有 Qt 应用程序都有一个全局线程池，我们可以使用QThreadPool::globalInstance()获得这个全局线程池
    Runnable *runnable = new Runnable;
    QThreadPool::globalInstance()->start(runnable);



}

MainWindow::~MainWindow()
{
}

