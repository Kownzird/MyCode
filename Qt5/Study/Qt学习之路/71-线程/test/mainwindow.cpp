#include "mainwindow.h"

#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QTimer>

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
}

MainWindow::~MainWindow()
{
}

