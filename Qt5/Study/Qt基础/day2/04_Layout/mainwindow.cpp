#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_2,&QPushButton::clicked, [=]{
        this->close();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

