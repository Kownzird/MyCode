#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openAction = new QAction(QIcon(":/image/doc-open"), tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip("Open an existing file...");
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu* file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar* toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
//    if(QMessageBox::Yes == QMessageBox::question(this,tr("Question"),tr("Are you OK?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
//    {
//        QMessageBox::information(this,tr("Hmmmm"),tr("I am glad to here that..."));
//    }
//    else
//    {
//        QMessageBox::information(this,tr("Hmmmm"),tr("I am sorry to here that..."));
//    }

    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified"));
    msgBox.setInformativeText(tr("Do you want to save your change?"));
    msgBox.setDetailedText(tr("Difference here..."));
    msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        qDebug() << "Save";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard";
        break;
    case QMessageBox::Cancel:
        qDebug() << "Cancel";
        break;

    }


}



