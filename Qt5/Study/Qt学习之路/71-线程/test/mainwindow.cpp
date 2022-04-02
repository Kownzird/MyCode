#include "mainwindow.h"
#include "workthread.h"

#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);

    QLCDNumber *lcdNumber = new QLCDNumber;
    layout->addWidget(lcdNumber);
    QPushButton *button = new QPushButton(tr("Start"), this);
    layout->addWidget(button);
    setCentralWidget(widget);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=](){
        static int sec = 0;
        lcdNumber->display(QString::number(sec++));
    });

    WorkThread *thread = new WorkThread(this);
    connect(thread, &WorkThread::done, timer, &QTimer::stop);
    connect(thread, &WorkThread::finished, thread, &WorkThread::deleteLater);
    connect(thread, &WorkThread::finished, [=](){
        qDebug() << "WorkThread thread finish";

        //断开button对象指针与clicked信号的任何连接
        disconnect(button, &QPushButton::clicked, 0, 0);
    });


    connect(button, &QPushButton::clicked, [=](){
        //QThread::start()函数启动一个线程
        //注意，这里不是run()函数
        //定时器timer 1ms产生一次溢出
        timer->start(1);
        thread->start();
    });

}

MainWindow::~MainWindow()
{
}

