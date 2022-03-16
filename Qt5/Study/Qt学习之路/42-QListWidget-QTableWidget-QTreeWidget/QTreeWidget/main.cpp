
#include <QApplication>
#include <QTreeWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTreeWidget treeWidget;
//    treeWidget.setColumnCount(1);

//    QTreeWidgetItem *root = new QTreeWidgetItem(&treeWidget, QStringList(QString("Root")));

//    new QTreeWidgetItem(root, QStringList(QString("Leaf 1")));
//    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root, QStringList(QString("Leaf 2")));
//    QTreeWidgetItem *leaf3 = new QTreeWidgetItem(leaf2, QStringList(QString("Leaf 3")));
//    leaf2->setCheckState(0,Qt::Checked);

//    QList<QTreeWidgetItem *> rootList;
//    rootList << root;
//    treeWidget.insertTopLevelItems(0, rootList);

//    treeWidget.show();
//    treeWidget.setHeaderHidden(true); //隐藏表头



    QTreeWidget treeWidget;

    QStringList headers;
    headers << "Name" << "Number";
    treeWidget.setHeaderLabels(headers);

    QStringList rootTextList;
    rootTextList << "Root" << "0";
    QTreeWidgetItem *root = new QTreeWidgetItem(&treeWidget, rootTextList);

    new QTreeWidgetItem(root, QStringList() << QString("Leaf 1") << "1");
    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root, QStringList() << "Leaf 2" << "2");
    leaf2->setCheckState(0, Qt::Checked);

    QTreeWidgetItem *leaf3 = new QTreeWidgetItem(leaf2, QStringList() << "Leaf 3" << "3");

    QList<QTreeWidgetItem *> rootList;
    rootList <<root;
    treeWidget.insertTopLevelItems(0, rootList);

    treeWidget.show();

    return a.exec();
}
