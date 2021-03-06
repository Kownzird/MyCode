#include "mainwindow.h"
#include <QTreeWidget>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("XML Reader"));
    treeWidget = new QTreeWidget(this);

    QStringList headers;
    headers <<"Items" << "Pages";
    treeWidget->setHeaderLabels(headers);

    setCentralWidget(treeWidget);
}

MainWindow::~MainWindow()
{
}


bool MainWindow::readFile(const QString &fileName){
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::critical(this, tr("Error"), tr("Can not read file %1").arg(fileName));
        return false;
    }

    reader = new QXmlStreamReader;
    reader->setDevice(&file);

    while(!reader->atEnd()){
        if(reader->isStartElement()){
            if(reader->name() == "bookindex"){
                readBookindexElement();
            }else{
                reader->raiseError(tr("Not a valid book file"));
            }
        }else{
            reader->readNext();
        }
    }
    file.close();

    if(reader->hasError()){
        QMessageBox::critical(this, tr("Error"), tr("Failed to parse file %1").arg(fileName));
        return false;
    }else if(file.error() != QFile::NoError){
        QMessageBox::critical(this, tr("Error"), tr("Cannot read file %1").arg(fileName));
        return false;
    }

    return true;
}

void MainWindow::readBookindexElement(){
    //如果在进入函数的时候，reader 不是StartElement状态，或者说标签不是 bookindex，就认为出错
    Q_ASSERT(reader->isStartElement() && reader->name() == "bookindex");
    reader->readNext();
    while(!reader->atEnd()){
        if(reader->isEndElement()){
            reader->readNext();
            break;
        }

        if(reader->isStartElement()){
            if(reader->name() == "entry"){
                readEntryElement(treeWidget->invisibleRootItem());
            }else{
                skipUnknownElement();
            }
        }else{
            reader->readNext();
        }
    }
}

void MainWindow::readEntryElement(QTreeWidgetItem *parent){
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, reader->attributes().value("term").toString());

    reader->readNext();
    while (!reader->atEnd()) {
        if(reader->isEndElement()){
            reader->readNext();
            break;
        }

        if(reader->isStartElement()){
            if(reader->name() == "entry"){
                readEntryElement(item);
            }else if(reader->name() == "page"){
                readPageElement(item);
            }else{
                skipUnknownElement();
            }
        }else{
            reader->readNext();
        }
    }
}

//遍历了 entry 下所有的 page 标签，将其拼接成合适的字符串
void MainWindow::readPageElement(QTreeWidgetItem *parent){
    QString page = reader->readElementText();
    if (reader->isEndElement()) {
        reader->readNext();
    }

    QString allPages = parent->text(1);
    if (!allPages.isEmpty()) {
        allPages += ", ";
    }
    allPages += page;
    parent->setText(1, allPages);
}


void MainWindow::skipUnknownElement(){
    reader->readNext();
    while (!reader->atEnd()) {
        if (reader->isEndElement()) {
            reader->readNext();
            break;
        }

        if (reader->isStartElement()) {
            skipUnknownElement();
        } else {
            reader->readNext();
        }
    }
}
