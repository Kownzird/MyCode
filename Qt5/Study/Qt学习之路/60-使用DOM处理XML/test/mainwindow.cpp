#include "mainwindow.h"
#include <QTreeWidget>
#include <QFile>
#include <QMessageBox>
#include <QDomDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("XML DOM Reader"));

    treeWidget = new QTreeWidget(this);

    QStringList headers;
    headers << "Items" << "Pages";
    treeWidget->setHeaderLabels(headers);

    setCentralWidget(treeWidget);
}

MainWindow::~MainWindow()
{
}

bool MainWindow::readFile(const QString &fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::critical(this, tr("Error"), tr("Cannot read file %1").arg(fileName));
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    //使用setContent()函数填充 DOM 树
    QDomDocument doc;
    if(!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)){
        QMessageBox::critical(this, tr("Error"), tr("Parse error at Line %1, Column %2: %3").\
                              arg(errorLine).arg(errorColumn).arg(errorStr));
        return false;
    }

    //获得一个 Document 元素
    QDomElement root = doc.documentElement();
    if(root.tagName() != "bookindex"){
        QMessageBox::critical(this, tr("Error"), tr("Not a book index file"));
        return false;
    }

    parseBookindexElement(root);
    return true;
}


void MainWindow::parseBookindexElement(const QDomElement &element){
    QDomNode child = element.firstChild();
    while(!child.isNull()){
        //toElement()函数将QDomNode转换成QDomElement
        if(child.toElement().tagName() == "entry"){
            parseEntryElement(child.toElement(), treeWidget->invisibleRootItem());
        }
        child = child.nextSibling();
    }
}


void MainWindow::parseEntryElement(const QDomElement &element, QTreeWidgetItem *parent){
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, element.attribute("term"));

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if(child.toElement().tagName() == "entry"){
            parseEntryElement(child.toElement(), item);
        }else if(child.toElement().tagName() == "page"){
            parsePageElement(child.toElement(), item);
        }
        child = child.nextSibling();
    }
}


void MainWindow::parsePageElement(const QDomElement &element, QTreeWidgetItem *parent){
    QString page = element.text();
    QString allPages = parent->text(1);
    if(!allPages.isEmpty()){
        allPages += ", ";
    }
    allPages += page;
    parent->setText(1, allPages);
}
