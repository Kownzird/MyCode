#include "mainwindow.h"
#include <QTextEdit>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == textEdit){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << "Ate key press" << keyEvent->key();
            return true;
        } else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        QMainWindow::eventFilter(obj,event);
    }
}
