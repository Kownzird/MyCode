#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openAction = new QAction(QIcon(":/images/open.png"),tr("&Open"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file..."));

    saveAction = new QAction(QIcon(":/images/save.png"),tr("&Save"),this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file..."));

    QMenu* file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar* toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    connect(textEdit,&QTextEdit::textChanged, [=](){
        this->setWindowModified(true);
    });

    setWindowTitle("TextPad [*]");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    //获取所选文件路径
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()){
        //文件存在
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("Read File"),tr("Can not open file\n%1").arg(path));
            return;
        }
        else{
            QTextStream in(&file);
            textEdit->setText(in.readAll());
            file.close();
        }
    }
    else{
        QMessageBox::warning(this,tr("Path"), tr("You did not select any file"));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,tr("Save File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            QMessageBox::warning(this, tr("Write File"), tr("Can not open file\n%1").arg(path));
            return;
        }else{
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        }
    }else{
        QMessageBox::warning(this,tr("Path"), tr("You did not select any file"));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isWindowModified()){
        bool exit = QMessageBox::warning(this,
                                         tr("Quit"),
                                         tr("Are you sure to quit this application?"),
                                         QMessageBox::Yes|QMessageBox::No,
                                         QMessageBox::Yes) == QMessageBox::Yes;
        if(exit){
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}


