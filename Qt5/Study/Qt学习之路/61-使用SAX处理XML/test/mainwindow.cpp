#include "mainwindow.h"
#include <QFile>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("XML Reader"));

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
    currentItem = 0;

    QFile file(fileName);
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;
    reader.setContentHandler(this);
    reader.setErrorHandler(this);
    return reader.parse(inputSource);
}

//第三个参数是标签的名字（正式的名字是“限定名”，qualified name，因此形参是 qName）；
//第四个参数是属性列表
bool MainWindow::startElement(const QString & /*namespaceURI*/,
                              const QString & /*localName*/,
                              const QString &qName,
                              const QXmlAttributes &attributes)
{
    if (qName == "entry") {
        currentItem = new QTreeWidgetItem(currentItem ? currentItem : treeWidget->invisibleRootItem());
        currentItem->setText(0, attributes.value("term"));
    } else if (qName == "page") {
        currentText.clear();
    }
    return true;
}



bool MainWindow::characters(const QString &str){
    currentText += str;
    return true;
}

bool MainWindow::endElement(const QString & /*namespaceURI*/,
                            const QString & /*localName*/,
                            const QString &qName)
{
    if (qName == "entry") {
        currentItem = currentItem->parent();
    } else if (qName == "page") {
        if (currentItem) {
            QString allPages = currentItem->text(1);
            if (!allPages.isEmpty())
                allPages += ", ";
            allPages += currentText;
            currentItem->setText(1, allPages);
        }
    }
    return true;
}

bool MainWindow::fatalError(const QXmlParseException &exception)
{
    QMessageBox::critical(this,
                          tr("SAX Error"),
                          tr("Parse error at line %1, column %2:\n %3")
                          .arg(exception.lineNumber())
                          .arg(exception.columnNumber())
                          .arg(exception.message()));
    return false;
}
