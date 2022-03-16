#include "mainwindow.h"
#include <QTextEdit>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    //QTextEdit可以接受从其它应用程序拖放过来的文本类型的数据
    //如果用户把一个文件拖到这面，默认会把文件名插入到光标位置
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    //让MainWindow截获拖放事件，而不是交给QTextEdit处理
    textEdit->setAcceptDrops(false);
    setAcceptDrops(true);

    setWindowTitle(tr("Text Editor"));
}

MainWindow::~MainWindow(){
}


//将文件拖动到组件时，系统会回调该函数
void MainWindow::dragEnterEvent(QDragEnterEvent *event){
    //此处是过滤文件类型，只有MIME类型为text/uri-list的才可接收
    if(event->mimeData()->hasFormat("text/uri-list")){
        //该函数可以使组件接受文件拖放
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event){
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty()){
        return;
    }

    //返回文件路径
    QString fileName = urls.first().toLocalFile();
    qDebug() << "fileName=" << fileName;
    qDebug() << "url=" << urls.first();
    if(fileName.isEmpty()){
        return;
    }

    if(readFile(fileName)){
        setWindowTitle(tr("%1-%2").arg(fileName, tr("Drag File")));
    }
}


bool MainWindow::readFile(const QString &fileName){
    bool r = false;
    QFile file(fileName);
    QString content;
    if(file.open(QIODevice::ReadOnly)){
        content = file.readAll();
        r = true;
    }
    textEdit->setText(content);
    return r;
}
